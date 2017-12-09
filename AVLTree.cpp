
#include <iostream>
#include "AVLTree.h"
using namespace std;

//static int arr[]= {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};
//#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

int main()
{
    int i,ilen,ii;
    AVLTree<int>* tree=new AVLTree<int>();

    cout << "����AVL��: ";
//    ilen = TBL_SIZE(arr);
    cout << "������Ԫ�ظ�����" << endl;
    cin >> ilen;
    for(i=0; i<ilen; i++)
    {
        int j;
        cin >> j;
        tree->insert(j);

//        cout << arr[i] <<" ";
//        tree->insert(arr[i]);
    }

    cout << "������ɣ�ǰ�����: ";
    tree->preOrder();

    cout << "\n�������: " ;
    tree->inOrder();
    cout << "\n��������ҵ�Ԫ�أ�" << endl;
    cin >> i;
    if (tree->search(i)) {
        cout << "���ҳɹ�: " << i << endl;
    } else {
        cout << "���޴���" << endl;
    }

    cout << "\n������ɾ���Ľڵ�: " << endl;
    cin >> ii;

    tree->remove(ii);

    cout << "\nɾ���� ǰ�����: " ;
    tree->preOrder();
//    tree->print();

    // ���ٶ�����
    tree->destroy();

    return 0;
}