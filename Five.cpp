#include<iostream>
#include<string>
#include<stack>
#include<list>
using namespace std;
class getstring
{
public:list <string> istream;
    stack<string> label;
    bool flag;
    list<string>::iterator getite(int i)
    {
        int j=0;
        list<string>::iterator it1=istream.begin();
        while(j!=i)
        {
            j++;it1++;
        }
        return it1;
    }
    void getis()
    {
        string s1,s2;
        cout<<"请输入表达式："<<endl;
        cin>>s1;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]=='+'||s1[i]=='*'||s1[i]=='('||s1[i]==')')
            {
                s2.push_back(s1[i]);istream.push_back(s2);s2.clear();
            }
            else if(s1[i]=='i')
            {
                s2.push_back(s1[i]);i++;
                if(s1[i]=='d'){s2.push_back(s1[i]);istream.push_back(s2);s2.clear();}
                else{error();}
            }
            else if(s1[i]=='\0')
            {
                continue;
            }
            else
            {error();}
        }
        istream.push_back("$");flag=false;
    }
    void error()
    {
        cout<<"错误！"<<endl;
        
    }
    void test()
    {
        if(label.empty()||istream.empty()){exit(0);}
    }
    void gototable(string s1,string s2)
    {
        if(s1=="0"&&s2=="E")
        {
            label.push("1");
        }
        if((s1=="0"||s1=="4")&&s2=="T")
        {
            label.push("2");
        }
        if((s1=="0"||s1=="4"||s1=="6")&&s2=="F")
        {
            label.push("3");
        }
        if(s1=="4"&&s2=="E")
        {
            label.push("8");
        }
        if(s1=="6"&&s2=="T")
        {
            label.push("9");
        }
        if(s1=="7"&&s2=="F")
        {
            label.push("10");
        }
    }
    void analyse()
    {
        label.push("0");
        string stop,listop,s1;
        while(!(label.empty()||istream.empty())&&!(label.top()=="1"&&istream.front()=="$"))
        {
            stop=label.top();listop=istream.front();
            if((stop=="0"||stop=="4"||stop=="6"||stop=="7")&&listop=="id")
            {
                label.push("id");label.push("5");istream.pop_front();cout<<"移进"<<endl;continue;
            }
            if((stop=="0"||stop=="4"||stop=="6"||stop=="7")&&listop=="(")
            {
                label.push("(");label.push("4");istream.pop_front();cout<<"移进"<<endl;continue;
            }
            if((stop=="1"||stop=="8")&&listop=="+")
            {
                label.push("+");label.push("6");istream.pop_front();cout<<"移进"<<endl;continue;
            }
            if((stop=="2"||stop=="9")&&listop=="*")
            {
                label.push("*");label.push("7");istream.pop_front();cout<<"移进"<<endl;continue;
            }
            if(stop=="8"&&listop==")")
            {
                label.push(")");label.push("11");istream.pop_front();cout<<"移进"<<endl;continue;
            }
            if(stop=="2"&&(listop=="+"||listop==")"||listop=="$"))
            {
                label.pop();test();label.pop();test();s1=label.top();label.push("E");gototable(s1,"E");
                cout<<"按E->T归约"<<endl;continue;
            }
            if(stop=="3"&&(listop=="+"||listop=="*"||listop==")"||listop=="$"))
            {
                label.pop();test();label.pop();test();s1=label.top();label.push("T");gototable(s1,"T");
                cout<<"按T->F归约"<<endl;continue;
            }
            if(stop=="5"&&(listop=="+"||listop=="*"||listop==")"||listop=="$"))
            {
                label.pop();test();label.pop();test();s1=label.top();label.push("F");gototable(s1,"F");
                cout<<"按F->id归约"<<endl;continue;
            }
            if(stop=="9"&&(listop=="+"||listop==")"||listop=="$"))
            {
                for(int i=0;i<6;i++){test();label.pop();}
                test();s1=label.top();label.push("E");gototable(s1,"E");
                cout<<"按E->E+T归约"<<endl;continue;
            }
            if(stop=="10"&&(listop=="+"||listop=="*"||listop==")"||listop=="$"))
            {
                for(int i=0;i<6;i++){test();label.pop();}
                test();s1=label.top();label.push("T");gototable(s1,"T");
                cout<<"按T->T*F归约"<<endl;continue;
            }
            if(stop=="11"&&(listop=="+"||listop=="*"||listop==")"||listop=="$"))
            {
                for(int i=0;i<6;i++){test();label.pop();}
                test();s1=label.top();label.push("F");gototable(s1,"F");
                cout<<"按F->(E)归约"<<endl;continue;
            }
            else
            {
                errorhand(stop,listop);continue;
            }
        }test();
        if(label.top()=="1"&&istream.front()=="$"&&!flag)
        {
            cout<<"接受"<<endl;
        }
    }
    void errorhand(string s1,string s2)
    {flag=true;
        if((s1=="0"||s1=="4"||s1=="6"||s1=="7")&&(s2=="+"||s2=="*"||s2=="$"))
        {label.push("id");
            label.push("5");cout<<"缺少操作数"<<endl;exit(0);
        }
        if((s1=="0"||s1=="1"||s1=="6"||s1=="7")&&s2==")")
        {
            istream.pop_front();cout<<"不匹配的右括号"<<endl;exit(0);
        }
        if((s1=="1"||s1=="8")&&(s2=="id"||s2=="("))
        {label.push("+");
            label.push("6");cout<<"缺少运算符+"<<endl;exit(0);
        }
        if((s1=="2"||s1=="9")&&(s2=="id"||s2=="("))
        {label.push("*");
            label.push("7");cout<<"缺少运算符*"<<endl;exit(0);
        }
        if(s1=="8"&&s2=="$")
        {
            label.push("11");cout<<"缺少右括号"<<endl;exit(0);
        }
        else
        {
            label.pop();cout<<"无效的输入"<<endl;
            return;
        }
    }
};

int main()
{
    getstring s1;
    s1.getis();

    s1.analyse();
    return 0;
}