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
///*栈的链式实现*/
//class linkstack
//{
//private:
//    linknode * top;
//public:
//    int size;
//    linkstack()/*构造函数初始化*/
//    {
//        top=NULL;
//        size=0;
//    }
//    void clear()/*清空栈内容*/
//    {
//        while(top!=NULL)
//        {
//            linknode * tmp=top;
//            top=top->link;
//            delete tmp;
//        }
//        size=0;
//    }
//    ~linkstack()/*析构函数*/
//    {
//        clear();
//    }
//    void push(int item)/*入栈操作的链式实现*/
//    {
//        linknode *tmp=new linknode(item,top);
//        top=tmp;
//        size++;
//    }
//    void pop(int & item)/*出栈操作的链式实现*/
//    {
//        linknode * tmp;
//        if(size==0)
//        {
//            cout<<"栈为空，不能执行出栈操作"<<endl;
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
//    void Top()/*读取栈中元素但不删除*/
//    {
//        int item;
//        linknode * tmp;
//        tmp=top;
//        if(size==0)
//        {
//            cout<<"栈为空，不能读取栈顶元素"<<endl;
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