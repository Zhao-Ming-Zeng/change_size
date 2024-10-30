#include <iostream>
using namespace std;

// 函式：打印陣列
void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";  // 打印陣列中的每個元素
    }
    cout << endl;  // 打印換行符
}

// 函式：變更陣列大小
void change_size(int*& arr, int size, int n_size) {
    if (n_size > size) {  // 如果新大小大於原始大小
        int* n_arr = new int[n_size];  // 分配一個新的陣列
        int* recycle = arr;  // 保存原始陣列的指標
        copy(arr, arr + size, n_arr);  // 將原始陣列內容複製到新陣列
        delete[] recycle;  // 釋放原始陣列的記憶體
        arr = n_arr;  // 更新指標，使其指向新的陣列

        // 初始化新增的元素
        for (int i = size; i < n_size; i++) {
            arr[i] = i;  // 將新擴展的部分初始化
        }
        cout << "擴展後陣列為：";  // 提示
        print_arr(arr, n_size);  // 打印擴展後的陣列
    }
    else {
        cout << "無法擴展" << endl;  // 如果新大小不大於原始大小，顯示錯誤消息
    }
}

// 主函式
void main() {
    int size;  // 用來儲存使用者輸入的陣列大小
    cout << "請輸入需要的陣列大小：";  // 提示使用者輸入陣列大小
    cin >> size;  // 讀取使用者輸入的大小
    int* arr = new int[size];  // 動態分配陣列

    for (int i = 0; i < size; i++) {
        arr[i] = i;  // 初始化陣列元素
    }
    cout << "擴展前陣列為：";  // 提示
    print_arr(arr, size);  // 打印擴展前的陣列
    cout << endl;

    int n_size;  // 用來儲存使用者希望擴展的大小
    cout << "請輸入想要變成的陣列大小：";  // 提示使用者輸入新的大小
    cin >> n_size;  // 讀取新的大小
    change_size(arr, size, n_size);  // 呼叫函式以變更陣列大小
}
