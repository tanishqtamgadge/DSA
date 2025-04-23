#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    
    vector<int> marks(n);
    cout << "Enter the marks obtained by students: ";
    for(int i = 0; i < n; i++) {
        cin >> marks[i];
    }

    // Max Heap (for maximum marks)
    priority_queue<int> maxHeap;
    // Min Heap (for minimum marks)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert marks into both heaps
    for(int mark : marks) {
        maxHeap.push(mark);
        minHeap.push(mark);
    }

    // Maximum marks (top of max heap)
    int maxMarks = maxHeap.top();

    // Minimum marks (top of min heap)
    int minMarks = minHeap.top();

    // Output results
    cout << "Maximum marks obtained: " << maxMarks << endl;
    cout << "Minimum marks obtained: " << minMarks << endl;

    return 0;
}
// output
// Enter number of students: 5
// Enter the marks obtained by students: 56 72 90 45 63
// Maximum marks obtained: 90
// Minimum marks obtained: 45