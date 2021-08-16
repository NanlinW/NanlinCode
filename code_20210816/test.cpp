#include <iostream>
#include <vector>
using namespace std;
//�ҵ������K�����
//1.�������������
//2.����k-1������Ȼ���±�ָ�������Ϊ��K���
int getStard(vector<int> arr) {
    int key = arr[0];
    int low = 0;
    int high = arr.size() - 1;
    while (low < high) {
        while (low < high&& arr[high] > key) {
            high--;
        }
        if (low < high) {
            arr[low] = arr[high];
        }
        while (low < high && key <= arr[low]) {
            low++;
        }
        if (low < high) {
            arr[high] = arr[low];
        }
    }
    key = arr[low];
    return key;
}

void sort(vector<int>& arr, int low, int high) { //����
    int key = arr[0];
    //�ҵ���׼key
    key = getStard(arr);
    //�ݹ�����
    sort(arr, low, key - 1);
    sort(arr, key + 1, high);
}

int findK(vector<int> arr, int K) {
    int len = arr.size();
    //����
    sort(arr, 0, len - 1);
    //��������K��
    return arr[len - K];
}

int main() {
    vector<int> arr = { 2,5,7,3,1 };
    int K = 2; //�������5
    int res = findK(arr, K);
    cout << res << endl;
    return 0;
}