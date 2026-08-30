

#include<bits/stdC++.h>
using namespace std;

char rod[] = {'S', 'A', 'D'};
vector<stack<int>> stacks(3);

void moveDisk(int a, int b)
{
    if (stacks[b].empty() || (!stacks[a].empty() && stacks[a].top() < stacks[b].top()))
    {
        cout << "Move disk " << stacks[a].top() << " from rod " << rod[a] << " to rod " << rod[b] << "\n";
        stacks[b].push(stacks[a].top());
        stacks[a].pop();
    }
    else
        moveDisk(b, a);
}

void towerOfHanoiI(int n)
{
    cout << "Tower of Hanoi for " << n << " disks:\n";

    int s = 0, a = 1, d = 2;
    for (int i = n; i > 0; i--)
        stacks[s].push(i);

    int totalMoves = (1 << n) - 1;
    if (n % 2 == 0)
        swap(a, d);

    for (int i = 1; i <= totalMoves; i++)
    {
        if (i % 3 == 0)
            moveDisk(a, d);
        else if (i % 3 == 1)
            moveDisk(s, d);
        else
            moveDisk(s, a);
    }
}

void towerOfHanoiR(int n, char s, char d,char a){
    if (n == 0) {
        return;
    }
    towerOfHanoiR(n - 1, s, a, d);
    cout << "Disk " << n << " moved from " << s<< " to " << d << endl;
    towerOfHanoiR(n - 1, a, d, s);
}

int main()
{
    int n ;
    cout<<"enter of disks ";
    cin>>n;
    cout<<"iterative approach"<<endl;
    towerOfHanoiI(n);
    cout<<"recursive approach"<<endl;
    towerOfHanoiR(n,'S','D','A');
    return 0;
}
