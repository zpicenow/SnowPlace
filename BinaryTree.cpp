//#include<iostream>
//using namespace std;
//class linknode
//{
//public:
//    int data;
//    linknode * link;
//    linknode(int el,linknode * ptr=0)
//    {
//        data=el;
//        link=ptr;
//    }
//};
///*ջ����ʽʵ��*/
//class linkstack
//{
//private:
//    linknode * top;
//public:
//    int size;
//    linkstack()/*���캯����ʼ��*/
//    {
//        top=NULL;
//        size=0;
//    }
//    void clear()/*���ջ����*/
//    {
//        while(top!=NULL)
//        {
//            linknode * tmp=top;
//            top=top->link;
//            delete tmp;
//        }
//        size=0;
//    }
//    ~linkstack()/*��������*/
//    {
//        clear();
//    }
//    void push(int item)/*��ջ��������ʽʵ��*/
//    {
//        linknode *tmp=new linknode(item,top);
//        top=tmp;
//        size++;
//    }
//    void pop(int & item)/*��ջ��������ʽʵ��*/
//    {
//        linknode * tmp;
//        if(size==0)
//        {
//            cout<<"ջΪ�գ�����ִ�г�ջ����"<<endl;
//        }
//        else
//        {
//            item=top->data;
//            tmp=top->link;
//            delete top;
//            top=tmp;
//            size--;
//        }
//    }
//    void Top()/*��ȡջ��Ԫ�ص���ɾ��*/
//    {
//        int item;
//        linknode * tmp;
//        tmp=top;
//        if(size==0)
//        {
//            cout<<"ջΪ�գ����ܶ�ȡջ��Ԫ��"<<endl;
//        }
//        else
//        {
//            for(int i=0;i<size;i++)
//            {
//                item=tmp->data;
//                tmp=tmp->link;
//                cout<<item;
//            }
//        }
//    }
//};
//int main()
//{
//    linkstack a;
//    int num,change;
//    cout<<"Input a number:";
//    cin>>num;
//    cout<<"Input the change:";
//    cin>>change;
//    while(num/change!=0)
//    {
//        a.push(num%change);
//        num=num/change;
//    }
//    a.push(num);
//    cout<<"FINAL IS: ";
//    while (a.size != 0) {
//        a.pop(num);
//        cout << num;
//    }
//    cout<<endl;
//    return 0;
//}