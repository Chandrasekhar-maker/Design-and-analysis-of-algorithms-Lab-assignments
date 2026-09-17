#include <iostream>
#include <limits>

using namespace std;

struct SUB {
    int sum;
    int left;
    int right;
};

SUB maxCrossingSubarray(int a[], int low, int high, int mid) {
    int leftSum = numeric_limits<int>::min();
    int current = 0;
    int leftMaxIndex = mid;

    for (int i = mid; i >= low; --i) {
        current += a[i];
        if (current > leftSum) {
            leftSum = current;
            leftMaxIndex = i;
        }
    }

    int rightSum = numeric_limits<int>::min();
    current = 0;
    int rightMaxIndex = mid + 1;

    for (int i = mid + 1; i <= high; ++i) {
        current += a[i];
        if (current > rightSum) {
            rightSum = current;
            rightMaxIndex = i;
        }
    }

    return {leftSum + rightSum, leftMaxIndex, rightMaxIndex};
}

SUB maxSubarray(int a[], int low, int high) {
    if (high == low) {
        return {a[low], low, high};
    }

    int mid = low + (high - low) / 2;

    SUB left = maxSubarray(a, low, mid);
    SUB right = maxSubarray(a, mid + 1, high);
    SUB cross = maxCrossingSubarray(a, low, high, mid);

    if (left.sum >= right.sum && left.sum >= cross.sum) {
        return left;
    } else if (right.sum >= left.sum && right.sum >= cross.sum) {
        return right;
    } else {
        return cross;
    }
}

int main() {
    int a[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

    SUB result = maxSubarray(a, 0, 15);

    cout << "max sum : " << result.sum << endl;
    cout << "left index : " << result.left << endl;
    cout << "right index : " << result.right << endl;

    return 0;
}