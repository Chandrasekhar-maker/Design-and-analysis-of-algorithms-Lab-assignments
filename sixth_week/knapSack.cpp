#include <iostream>
#include <algorithm>
using namespace std;

class Item {
public:
    int value;
    int weight;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {

    int n;
    double capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];

    cout << "Enter value and weight of each item:\n";

    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;

        items[i].ratio =
            (double)items[i].value / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

   
    sort(items, items + n, compare);

    double maxValue = 0;

    for (int i = 0; i < n; i++) {

        if (capacity >= items[i].weight) {

           
            capacity -= items[i].weight;
            maxValue += items[i].value;
        }
        else {

            
            maxValue += items[i].ratio * capacity;
            capacity = 0;

            break;
        }
    }

    cout << "Maximum value = " << maxValue << endl;

    return 0;
}
