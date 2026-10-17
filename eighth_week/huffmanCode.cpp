
#include<bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char character, int frequency) {
        ch = character;
        freq = frequency;
        left = right = NULL;
    }
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void printCodes(Node* root, string str) {
    if (!root)
        return;

    if (root->ch != '$')
        cout << root->ch << ": " << str << endl;

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void huffmanCoding(vector<char>& characters, vector<int>& frequencies) {
    priority_queue<Node*, vector<Node*>, compare> pq;

    for (size_t i = 0; i < characters.size(); ++i) {
        pq.push(new Node(characters[i], frequencies[i]));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    printCodes(pq.top(), "");
}

int main() {
    vector<char> characters = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> frequencies = {5, 9, 12, 13, 16, 45};

    huffmanCoding(characters, frequencies);

    return 0;
}
