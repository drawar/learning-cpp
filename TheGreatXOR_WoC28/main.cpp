#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstddef>
using namespace std;

#define MAXN 100000
/*long pown_l(unsigned x, unsigned n);

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        long x;
        cin >> x;
        int i = ceil(log2(x+1))-1;
        cout << pown_l(2,i+1) - x - 1 << endl;
    }
    return 0;
}

long pown_l(unsigned x, unsigned n)
{
    long y = 1;
    for (unsigned i = 0; i < n; i++)
        y *= x;
    return y;
}

 int main(){
    string number;
    cin >> number;
    cout << number[0] << endl;
    cout << number.size() << endl;
    cout << std::numeric_limits<unsigned long long>::max() % 1000000007 <<endl;
    return 0;
}
 */


/*
 * Peak finding in 1D and 2D
int findPeak1D (int arr[], int start, int end);

int findPeak2D (int arr[][4], int startColIdx, int endColIdx);

int main(){
    int a[] = {7,12,13,10,5,6,8,2,4};
    int b[] = {1};
    int c[] = {1,2,3,4,5,6};
    int d[][4] ={{10,8,10,10},
                {14,13,12,11},
                {15,9,11,21},
                {16,17,19,20}};
    int size = sizeof(a)/sizeof(a[0]);
    cout << findPeak1D(a, 0, 8) << endl;
    cout << findPeak1D(b, 0, 0) << endl;
    cout << findPeak1D(c, 0, 5) << endl;
    cout << findPeak2D(d, 0, 3) << endl;
    return 0;
}

int findPeak1D (int arr[], int start, int end){
    //start and end are 0-based indices
    if (start == end)
        return arr[start];
    else {
        int mid = (start + end)/2;
        if (arr[mid] < arr[mid-1]){
            end = mid-1;
            return findPeak1D (arr, start, end);
        }
        else if (arr[mid] < arr[mid+1]){
            start = mid+1;
            return findPeak1D(arr, start, end);
        }
        else return arr[mid];
    }
}

int findPeak2D (int arr[][4], int startColIdx, int endColIdx) {
    int nCol = sizeof(arr[0]) / sizeof(arr[0][0]);
    int nRow = 4;
    if (startColIdx == endColIdx) {
        //max = arr[0][startColIdx];
        int maxIdx = 0;
        for (int i = 1; i < nRow; i++) {
            if (arr[i][startColIdx] > arr[i - 1][startColIdx]) {
                maxIdx = i;
            }
        }
        return arr[maxIdx][startColIdx];
    } else {
        int midColIdx = (startColIdx + endColIdx) / 2;
        int maxIdx = 0;
        for (int i = 1; i < nRow; i++) {
            if (arr[i][midColIdx] > arr[i - 1][midColIdx]) {
                maxIdx = i;
            }
            cout << maxIdx << endl;
        }
        if (arr[maxIdx][midColIdx - 1] > arr[maxIdx][midColIdx]) {
            endColIdx = midColIdx - 1;
            return findPeak2D(arr, startColIdx, endColIdx);
            } else if (arr[maxIdx][midColIdx + 1] > arr[maxIdx][midColIdx]) {
                startColIdx = midColIdx + 1;
                return findPeak2D(arr, startColIdx, endColIdx);
            } else return arr[maxIdx][midColIdx];

        }

}
 */

/*

struct Node{
    int data;
    Node* next;
};

void sortedInsert(Node*& head, int data){
    if (head == NULL || data < head->data){
        Node *newNode = new Node;
        newNode->next = head;
        newNode->data = data;
        head = newNode;
    }
    else {
        Node *cur = head;
        while (cur->next != NULL && cur->next->data < data) {
            cur = cur->next;
        }
            Node *newNode = new Node;
            newNode->next = cur->next;
            newNode->data = data;
            cur->next = newNode;

    }
}



int main(){
    Node *myNode = NULL;
    sortedInsert(myNode,7);

    cout << myNode->data << endl;
    //cout << myNode->next->data << endl;
    return 0;
}
 */

/*
int g_n = 42;

void func_ptr(int*& pp);

void example_ptr();

int main(){
    example_ptr();
    return 0;
}

void example_ptr()
{
    int n = 23;
    int* pn = &n;

    std::cout << "example_ptr()" << std::endl;

    std::cout << "Before :" << *pn << std::endl; // display 23

    func_ptr(pn);

    std::cout << "After :" << *pn << std::endl; // display 23
}

void func_ptr(int*& pp)
{
    pp = &g_n;
}
 */

// Task: Insert a node into a sorted linked list

#include <iostream>
#include <cstddef>

using namespace std;

struct Node{
    int _data;
    Node* _next;
    Node(){
        _next = NULL;
    }
    Node(int data){
        _data = data;
        _next = NULL;
    }
    Node(int data, Node* next){
        _data = data;
        _next = next;
    }
};


//reference to pointer as head needs to be modified
void sortedInsert(Node*& head, int data) {
    Node *newNode = new Node(data);
    if (head == NULL || data < head->_data ){
        newNode->_next = head;
        head = newNode;
    }
    else {
        Node* cur = head;
        while (cur->_next != NULL && cur->_next->_data < data)
            cur = cur->_next;
        newNode->_next = cur->_next;
        cur->_next = newNode;
    }
}

void print(Node *h){
    while(h){
        cout << h->_data << endl;
        h = h->_next;
    }
}


int main()
{
    Node* head = new Node(2);
    head->_next = new Node(4);
    head->_next->_next = new Node(4);
    sortedInsert(head,3);
    print(head);
    return 0;
}