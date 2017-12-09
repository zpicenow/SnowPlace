//#include <iostream>
//#include <queue>
//#include <stack>
//
//using namespace std;
//
//template<class T>
//class BinaryTreeNode{
//
//
//public:
//    T element;
//    BinaryTreeNode<T> *leftChild ;
//
//    BinaryTreeNode<T> *rightChild ;
//public:
//    BinaryTreeNode() {
//        element = 0;
//        leftChild = nullptr;
//        rightChild = nullptr;
//
//    }
//
//    ~BinaryTreeNode() ;
//
//    explicit BinaryTreeNode(const T &ele) ;
//
//    BinaryTreeNode(const T &ele, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r) ;
//
//    BinaryTreeNode<T> *getLeftChild() const ;
//
//    BinaryTreeNode<T> *getRightChild() const ;
//
//    void setLeftChild(BinaryTreeNode<T> *l) ;
//
//    void setRightChild(BinaryTreeNode<T> *r);
//
//    T getValue() const ;
//
//    void setValue(const T &val) ;
//
//    bool isLeaf() const ;
//};
//
//template <class T>
//BinaryTreeNode<T>::~BinaryTreeNode() {
////        delete (leftChild, rightChild);
//}
//
//template <class T>
//BinaryTreeNode<T>::BinaryTreeNode(const T &ele) {
//    element = ele;
//    leftChild = nullptr;
//    rightChild = nullptr;
//}
//
//template <class T>
//BinaryTreeNode<T>::BinaryTreeNode(const T &ele, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r) {
//    element = ele;
//    leftChild = l;
//    rightChild = r;
//
//}
//
//template <class T>
//BinaryTreeNode<T> *BinaryTreeNode<T>::getLeftChild() const {
//
//    return leftChild;
//}
//
//template <class T>
//BinaryTreeNode<T> *BinaryTreeNode<T>::getRightChild() const {
//    return rightChild;
//}
//
//template <class T>
//void BinaryTreeNode<T>::setLeftChild(BinaryTreeNode<T> *l) {
//    leftChild = l;
//}
//
//template <class T>
//void BinaryTreeNode<T>::setRightChild(BinaryTreeNode<T> *r) {
//    rightChild = r;
//}
//
//template <class T>
//T BinaryTreeNode<T>::getValue() const {
//    return element;
//
//}
//
//template <class T>
//void BinaryTreeNode<T>::setValue(const T &val) {
//    element = val;
//}
//
//template <class T>
//bool BinaryTreeNode<T>::isLeaf() const {
//    return (leftChild && rightChild);
//
//}
//
//template<class T>
//class BinaryTree {
//
//public:
//    BinaryTreeNode<T> *root ;
//public:
//    BinaryTree() {
//        root = nullptr;
//    }
////
//    ~BinaryTree() {
//        delete (root);
//    }
//
//    BinaryTreeNode<T> *createBinaryTree() {
//        BinaryTreeNode<T> *current = nullptr;
//        T value;
//        cin >> value;
//        if (value == '/') {
//            return nullptr;
//        } else {
//
//            current = new BinaryTreeNode<T>;
//
//            current->element = value;
//            current->leftChild = createBinaryTree();
//            current->rightChild = createBinaryTree();
//            return current;
//        }
//    }
//
//    bool isEmpty() const {
//        return root == nullptr;
//    }
//
//    BinaryTreeNode<T> *getRoot() const {
//        return root;
//
//    }
//
//    void setRoot(BinaryTreeNode<T> *rt) {
//        root = rt;
//    }
//
//    BinaryTreeNode<T> *getParetn() const {
//        return nullptr;
//
//    }
//
//    BinaryTreeNode<T> *getLeftSibling() const {
//        return nullptr;
//
//    }
//
//    BinaryTreeNode<T> *getRightSibling() const {
//        return nullptr;
//
//    }
//
//    void breadthFirstOrder(BinaryTreeNode<T> *rt) {
//
//    }
//
//    void preOrder(BinaryTreeNode<T> *rt) {
//
//        if (rt != nullptr) {
//
//            visit(rt);
//            preOrder(rt->leftChild);
//            preOrder(rt->rightChild);
//        }
//
//    }
//    void preOrderNotByRecursion(BinaryTreeNode<T> *rt) {
//        stack<BinaryTreeNode<T> *> nodeStack;
//        BinaryTreeNode<T> *pointer = rt;
//        while (!nodeStack.empty() || pointer) {
//            if (pointer) {
//                visit(pointer);
//                if (pointer->rightChild != nullptr) {
//                    nodeStack.push(pointer->rightChild);
//
//                } pointer = pointer->leftChild;
//            }else {
//
//                pointer = nodeStack.top();
//                nodeStack.pop();
//            }
//        }
//    }
//
//    void inOrder(BinaryTreeNode<T> *rt) {
//
//        if (rt != nullptr) {
//
//            inOrder(rt->leftChild);
//            visit(rt);
//            inOrder(rt->rightChild);
//        }
//    }
//
//    void inOrderNotByRecursion(BinaryTreeNode<T> *rt) {
//        stack<BinaryTreeNode<T> *> nodeStack;
//        BinaryTreeNode<T> *point = rt;
//
//        while (!nodeStack.empty() || point) {
//            if (point) {
//                nodeStack.push(point);
//
//                point = point->leftChild;
//
//            } else {
//                point = nodeStack.top();
//                visit(point);
//                point = point->rightChild;
//
//                nodeStack.pop();
//            }
//        }
//    }
//    void postOrder(BinaryTreeNode<T> *rt) {
//
//        if (rt != nullptr) {
//            postOrder(rt->leftChild);
//            postOrder(rt->rightChild);
//            visit(rt);
//        }
//    }
//
//    void postOrderNotByRecursion(BinaryTreeNode<T> *rt) {
//        stack<BinaryTreeNode<T> *> nodeStack;
//        BinaryTreeNode<T> *pointer = rt;
//        BinaryTreeNode<T> *pre = rt;
//        while (pointer) {
//            for (; pointer->leftChild != nullptr; pointer = pointer->leftChild) {
//                nodeStack.push(pointer);
//            }
//            while (pointer != nullptr && (pointer->rightChild == nullptr || pointer->rightChild == pre)) {
//                visit(pointer);
//                pre = pointer;
//                if (nodeStack.empty()) {
//                    return;
//
//                }
//                pointer = nodeStack.top();
//                nodeStack.pop();
//            }
//            nodeStack.push(pointer);
//
//
//            pointer = pointer->rightChild;
//        }
//    }
//    void visit(BinaryTreeNode<T> *pNode) {
//        cout << pNode->element << "  ";
//
//
//    }
//
//    void levelOrder(BinaryTreeNode<T> *rt) {
//        queue<BinaryTreeNode<T> *> nodeQueue;
//        cout << "广度遍历结果：" << endl;
//        BinaryTreeNode<T> *pointer = root;
//        if (pointer) {
//            nodeQueue.push(pointer);
//        }
//        while (!nodeQueue.empty()) {
//            pointer = nodeQueue.front();
//            visit(pointer);
//            nodeQueue.pop();
//            if (pointer->leftChild) {
//                nodeQueue.push(pointer->leftChild);
//            }
//            if (pointer->rightChild) {
//                nodeQueue.push(pointer->rightChild);
//            }
//        }
//        cout <<"\b"<< endl;
//    }
//
//    void createBTreeByPreAndIn(BinaryTreeNode<T> *&bTree, const string &preOrderString, const string &inOrderString) {
//
//        if (!preOrderString.length()) {
//
//            bTree = nullptr;
//            return;
//        }
//
//        char rootNode = preOrderString[0];
//        unsigned long index = (inOrderString.find(rootNode));
//        string leftChildInOrderString = inOrderString.substr(0, index);
//        string rightChildInOrderString = inOrderString.substr(index + 1);
//
//        auto leftChildStringLength = leftChildInOrderString.length();
//
//        auto rightChildStringLength = rightChildInOrderString.length();
//        string leftChildPreOrderString = preOrderString.substr(1, leftChildStringLength);
//        string rightChildPreOrderString = preOrderString.substr(1 + leftChildStringLength);
////        if (bTree) {
//        bTree = new BinaryTreeNode<T>;
//        bTree->element = rootNode;
//        createBTreeByPreAndIn(bTree->leftChild, leftChildPreOrderString, leftChildInOrderString);
//        createBTreeByPreAndIn(bTree->rightChild, rightChildPreOrderString, rightChildInOrderString);
////        }
//    }
//
//    void createBTreeByPostAndIn(BinaryTreeNode<T> *&bTree, const string &inOrderString, const string &postOrderString) {
//        if (!inOrderString.length()) {
//            bTree = nullptr;
//            return;
//
//        }
//        char rootNode = postOrderString[postOrderString.length() - 1];
//        unsigned long index = inOrderString.find(rootNode);
//        string leftChildInOrderString = inOrderString.substr(0, index);
//        string rightChildInOrderString = inOrderString.substr(index + 1);
//        unsigned long leftChildStringLength = leftChildInOrderString.length();
//        unsigned long rightChildStringLength = rightChildInOrderString.length();
//        string leftChildPostOrderString = postOrderString.substr(0, leftChildStringLength);
//        string rightChildPostOrderString = postOrderString.substr(leftChildStringLength, rightChildStringLength);
//
//        bTree = new BinaryTreeNode<T>;
//        bTree->element = rootNode;
//        createBTreeByPostAndIn(bTree->leftChild, leftChildInOrderString, leftChildPostOrderString);
//        createBTreeByPostAndIn(bTree->rightChild, rightChildInOrderString, rightChildPostOrderString);
//
//    }
//
//
//    void deleteBinaryTree(BinaryTreeNode<T> *rt) {
//        if (rt) {
//            deleteBinaryTree(rt->leftChild);
//            deleteBinaryTree(rt->rightChild);
//            delete rt;
//        } else return;
//
//    }
//
//
//    void numberOfDegree(BinaryTreeNode<T> *rt, int degree, int &num);
//
//    int heightOfBinaryTree(BinaryTreeNode<T> *rt);
//
//    int biggestWidth(BinaryTreeNode<T> *rt);
//
//    T maxElement(BinaryTreeNode<T> *rt);
//
//    void reverseLeftAndRight(BinaryTreeNode<T> *rt);
//
//    void deleteLevesNode(BinaryTreeNode<T> *rt);
//
//    bool isCompleteBTree(BinaryTreeNode<T> *rt);
//
//
//    void dfsNumsOfDepth(const BinaryTreeNode<T> *rt,
//                        const int depth, int curD, int *pInt)
//    {
//        if (!rt || curD > depth)
//            return;
//
//
//
//        else if (curD < depth)
//        {
//            dfsNumsOfDepth(rt->getLeftChild(),
//                           depth, curD + 1, pInt);
//            dfsNumsOfDepth(rt->getRightChild(),
//                           depth, curD + 1, pInt);
//        }
//        else
//
//
//
//        {
//            (*pInt)++;
//        }
//    }
//
//    void showBigWidthTree( BinaryTreeNode<T> *rt)
//    {
//        int height = heightOfBinaryTree(rt);
//
//
//
//        int width = 0, maxWidth = 0, depth = 1;
//
//        for (int i = 1; i <= height; i++)
//        {
//            width = 0;
//            dfsNumsOfDepth(rt, i, 1, &width);
//
//            if (width > maxWidth)
//            {
//                maxWidth = width;
//            }
//        }
//
//        cout << "最大宽度为： " << maxWidth << endl;
//    }
//};
//
//template<class T>
//void BinaryTree<T>::numberOfDegree(BinaryTreeNode<T> *rt, int degree, int &num) {
//
//    if (rt ) {
//        switch (degree) {
//            case 0:
//                if (rt->getLeftChild() == nullptr & rt->getRightChild() == nullptr) {
//                    num++;
//                }
//
//                break;
//            case 1:
//                if ((rt->getLeftChild() == nullptr & rt->getRightChild() != nullptr) |
//                    (rt->getRightChild() == nullptr & rt->getLeftChild() != nullptr)) {
//
//
//                    num++;
//                }
//                break;
//            case 2:
//                if (rt->getLeftChild() && rt->getRightChild()) {
//                    num++;
//
//                }
//                break;
//            default:
//                break;
//        }
//        numberOfDegree(rt->getLeftChild(), degree, num);
//        numberOfDegree(rt->getRightChild(), degree, num);
//    }
//
//
//
//
//}
//
//template<class T>
//int BinaryTree<T>::heightOfBinaryTree(BinaryTreeNode<T> *rt) {
//
//    int height = 0;
//    if (rt) {
//
//        int leftHeight = heightOfBinaryTree(rt->getLeftChild());
//        int rightHeight = heightOfBinaryTree(rt->getRightChild());
//        height = leftHeight >= rightHeight ? leftHeight + 1 : rightHeight + 1;
//
//    }
//
//    return height;
//}
//
//template<class T>
//int BinaryTree<T>::biggestWidth(BinaryTreeNode<T> *rt) {
//    if (!rt) {
//        return 0;
//    }
//    int width = 0;
//    int lastLevelWidth = 0;
//    int currentLevelWidth = 0;
//    int tempWidth = 0;
//    queue<BinaryTreeNode<T> *> widthQueue;
//    widthQueue.push(rt);
//    lastLevelWidth = 1;
//    BinaryTreeNode<T> *pCur = nullptr;
//    while (!widthQueue.empty()) {
//        tempWidth = lastLevelWidth;
//        while (tempWidth != 0) {
//            pCur = widthQueue.front();
//            widthQueue.pop();
//            if (pCur->getLeftChild() != nullptr) {
//                widthQueue.push(pCur->getLeftChild());
//
//            }
//            if (pCur->getRightChild() != nullptr) {
//                widthQueue.push(pCur->getRightChild());
//            }
//            tempWidth--;
//        }
//        currentLevelWidth = static_cast<int>(widthQueue.size());
//        width = currentLevelWidth > width ? currentLevelWidth : width;
//        lastLevelWidth = currentLevelWidth;
//    }
//    return width;
//
//}
//
//template<class T>
//T BinaryTree<T>::maxElement(BinaryTreeNode<T> *rt) {
//    if (rt == nullptr) {
//        return 0;
//    }
//    T maxLeft = maxElement(rt->getLeftChild());
//    T maxRight = maxElement(rt->getRightChild());
//    T maxElement = maxLeft > maxRight ? maxLeft : maxRight;
//    return maxElement > rt->getValue() ? maxElement : rt->getValue();
//}
//
//template<class T>
//void BinaryTree<T>::reverseLeftAndRight(BinaryTreeNode<T> *rt) {
//    if (!rt) {
//        return;
//
//    }
//    BinaryTreeNode<T> *temp = nullptr;
//    temp = rt->getLeftChild();
//    rt->setLeftChild(rt->getRightChild());
//    rt->setRightChild(temp);
//    reverseLeftAndRight(rt->getLeftChild());
//    reverseLeftAndRight(rt->getRightChild());
//}
//
//template<class T>
//void BinaryTree<T>::deleteLevesNode(BinaryTreeNode<T> *rt) {
//    if (rt == nullptr)
//        return;
//
//    if (!rt->getLeftChild() && !rt->getRightChild())
//        return;
//
//    if (rt->getLeftChild())
//
//
//    {
//        if (rt->getLeftChild()->getLeftChild() || rt->getLeftChild()->getRightChild()) {
//
//            deleteLevesNode(rt->getLeftChild());
//
//        } else
//        {
//
//            delete rt->getLeftChild();
//            rt->setLeftChild(nullptr);
//
//        }
//
//    }
//
//
//    if (rt->getRightChild())
//    {
//        if (rt->getRightChild()->getLeftChild() || rt->getRightChild()->getRightChild()) {
//            deleteLevesNode(rt->getRightChild());
//        } else //当前节点的右子节点是叶子
//        {
//            delete rt->getRightChild();
//            rt->setRightChild(nullptr);
//        }
//    }
//
//}
//
//template<class T>
//bool BinaryTree<T>::isCompleteBTree(BinaryTreeNode<T> *rt) {
//    if (!rt) {
//        return true;
//    }
//    BinaryTreeNode<T> *temp = nullptr;
//    queue<BinaryTreeNode<T> *> nodeQueue;
//    nodeQueue.push(rt);
//    while (temp = nodeQueue.front()) {
//        nodeQueue.push(temp->getLeftChild());
//        nodeQueue.push(temp->getRightChild());
//        nodeQueue.pop();
//    }
//    while (!nodeQueue.empty()) {
//        temp = nodeQueue.front();
//        if (temp != nullptr) {
//            return false;
//        }
//        nodeQueue.pop();
//    }
//    return true;
//
//}
//
//int main() {
//
//    cout << "开始创建一个二叉树：" << endl;
//    BinaryTree<char> binaryTree;
////    string string1, string2;
////    int choice;
////    cout << "====请选择===\n1：\t根据先序和中序遍历结果创建二叉树\n2：\t根据中序和后序遍历结果创建二叉树\n===============\n";
////    cin >> choice;
////    switch (choice) {
////        case 1:
////            cout << "请输入先序及中序遍历结果：" << endl;
////
////            cin >> string1 >> string2;
////            binaryTree.createBTreeByPreAndIn(binaryTree.root, string1, string2);
////
////            break;
////        case 2:
////            cout << "请输入中序及后序遍历结果：" << endl;
////
////            cin >> string1 >> string2;
////            binaryTree.createBTreeByPostAndIn(binaryTree.root, string1, string2);
////            break;
////        default:break;
////    }
//
//    binaryTree.setRoot(binaryTree.createBinaryTree());
////    binaryTree.levelOrder(binaryTree.getRoot());
////    cout << endl << "前序：" << endl;
////    binaryTree.preOrderNotByRecursion(binaryTree.getRoot());
////    cout << endl << "中序" << endl;
////    binaryTree.inOrderNotByRecursion(binaryTree.getRoot());
////    cout << endl << "后序" << endl;
////    binaryTree.postOrderNotByRecursion(binaryTree.getRoot());
//
//    int num = 0;
//    binaryTree.numberOfDegree(binaryTree.getRoot(), 0, num);
//    cout << "度数为0的节点数： " << num << endl;
//    num = 0;
//    binaryTree.numberOfDegree(binaryTree.getRoot(), 1, num);
//    cout << "度数为1的节点数： " <<num << endl;
//    num = 0;
//    binaryTree.numberOfDegree(binaryTree.getRoot(), 2, num);
//    cout << "度数为2的节点数： " <<num << endl;
//    cout << "高度为：" << binaryTree.heightOfBinaryTree(binaryTree.getRoot()) << endl;
////    cout << "宽度为： " << binaryTree.biggestWidth(binaryTree.getRoot()) << endl;
//    binaryTree.showBigWidthTree(binaryTree.getRoot());
//    cout << "最大元素的值： " << binaryTree.maxElement(binaryTree.getRoot()) << endl;
//    cout << "交换左右节点前" ;
//    binaryTree.levelOrder(binaryTree.getRoot());
//
//    binaryTree.reverseLeftAndRight(binaryTree.getRoot());
//    cout << "交换左右节点后" ;
//    binaryTree.levelOrder(binaryTree.getRoot());
//    cout << "删除叶子节点之后： " << endl;
//    binaryTree.deleteLevesNode(binaryTree.getRoot());
//    binaryTree.levelOrder(binaryTree.getRoot());
//    if (binaryTree.isCompleteBTree(binaryTree.getRoot())) {
//        cout << "完全二叉树" << endl;
//    } else {
//        cout << "非完全二叉树" << endl;
//
//    }
////    binaryTree.reverseLeftAndRight(binaryTree.getRoot());
////    binaryTree.deleteLevesNode(binaryTree.getRoot());
////    binaryTree.levelOrder(binaryTree.getRoot());
////    cout << binaryTree.isCompleteBTree(binaryTree.getRoot()) << endl;
//
//    return 0;
//}
