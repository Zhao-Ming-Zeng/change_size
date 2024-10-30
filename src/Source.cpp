#include <iostream>
using namespace std;

// �禡�G���L�}�C
void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";  // ���L�}�C�����C�Ӥ���
    }
    cout << endl;  // ���L�����
}

// �禡�G�ܧ�}�C�j�p
void change_size(int*& arr, int size, int n_size) {
    if (n_size > size) {  // �p�G�s�j�p�j���l�j�p
        int* n_arr = new int[n_size];  // ���t�@�ӷs���}�C
        int* recycle = arr;  // �O�s��l�}�C������
        copy(arr, arr + size, n_arr);  // �N��l�}�C���e�ƻs��s�}�C
        delete[] recycle;  // �����l�}�C���O����
        arr = n_arr;  // ��s���СA�Ϩ���V�s���}�C

        // ��l�Ʒs�W������
        for (int i = size; i < n_size; i++) {
            arr[i] = i;  // �N�s�X�i��������l��
        }
        cout << "�X�i��}�C���G";  // ����
        print_arr(arr, n_size);  // ���L�X�i�᪺�}�C
    }
    else {
        cout << "�L�k�X�i" << endl;  // �p�G�s�j�p���j���l�j�p�A��ܿ��~����
    }
}

// �D�禡
void main() {
    int size;  // �Ψ��x�s�ϥΪ̿�J���}�C�j�p
    cout << "�п�J�ݭn���}�C�j�p�G";  // ���ܨϥΪ̿�J�}�C�j�p
    cin >> size;  // Ū���ϥΪ̿�J���j�p
    int* arr = new int[size];  // �ʺA���t�}�C

    for (int i = 0; i < size; i++) {
        arr[i] = i;  // ��l�ư}�C����
    }
    cout << "�X�i�e�}�C���G";  // ����
    print_arr(arr, size);  // ���L�X�i�e���}�C
    cout << endl;

    int n_size;  // �Ψ��x�s�ϥΪ̧Ʊ��X�i���j�p
    cout << "�п�J�Q�n�ܦ����}�C�j�p�G";  // ���ܨϥΪ̿�J�s���j�p
    cin >> n_size;  // Ū���s���j�p
    change_size(arr, size, n_size);  // �I�s�禡�H�ܧ�}�C�j�p
}
