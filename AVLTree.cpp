
#include <iostream>
#include "AVLTree.h"
using namespace std;

//static int arr[]= {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};
//#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

int main()
{
    int i,ilen,ii;
    AVLTree<int>* tree=new AVLTree<int>();

    cout << "构建AVL树: ";
//    ilen = TBL_SIZE(arr);
    cout << "请输入元素个数：" << endl;
    cin >> ilen;
    for(i=0; i<ilen; i++)
    {
        int j;
        cin >> j;
        tree->insert(j);

//        cout << arr[i] <<" ";
//        tree->insert(arr[i]);
    }

    cout << "构建完成，前序遍历: ";
    tree->preOrder();

    cout << "\n中序遍历: " ;
    tree->inOrder();
    cout << "\n请输入查找的元素：" << endl;
    cin >> i;
    if (tree->search(i)) {
        cout << "查找成功: " << i << endl;
    } else {
        cout << "查无此数" << endl;
    }

    cout << "\n请输入删除的节点: " << endl;
    cin >> ii;

    tree->remove(ii);

    cout << "\n删除后 前序遍历: " ;
    tree->preOrder();
//    tree->print();

    // 销毁二叉树
    tree->destroy();

    return 0;
}