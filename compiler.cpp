//
// Created by zpice on 2018/10/16.
//

#include <cstdio>
#include <stack>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <functional>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
const int N=1000;
int n,m;
struct Set
{
    char s[100];
    int n;
    Set():n(0) {}
    void insert(char c)
    {
        int i;
        for (i=0;i<n;i++) if (c==s[i]) return;
        s[n++]=c;
    }
    char get(int i)
    {
        return s[i];
    }
    void And(Set a)
    {
        int i,j;
        for (i=0;i<a.n;i++) {
            for (j=0;j<n;j++) if (s[j]==a.get(i)) break;
            if (j==n) insert(a.get(i));
        }
    }
    void show()
    {
        for (int i=0;i<n;i++) cout<<s[i]<<" "; cout<<endl;
    }
    int find(char c)
    {
        for (int i=0;i<n;i++) if (s[i]==c) return i;
        return -1;
    }
    void delete_block()
    {
        int i;
        for (i=0;i<n;i++) if (s[i]=='$') break;
        if (i<n) {
            for (;i+1<n;i++) s[i]=s[i+1];
            n--;
        }
    }
};
class LL1
{
public:
    int n;
    string table[100][100] ;
    string l[N],r[N];
    Set first[N],follow[N],select[N],vt,vn;
    map<string,bool> block;  // true represent it has $
    LL1():n(0) {}
    void getblock()
    {
        int i,j,e,k;
        k=0,e=0;
        int pos[N],posBlock[N];
        for (i=0;i<n;i++){
            for (j=0;j<r[i].size();j++) {
                char c=r[i][j];
                if (!isupper(c)) break;
            }
            if (j==r[i].size()) {
                pos[k++]=i;
            }
            if (r[i]=="$") block[l[i]]=true;
        }  //cout<<k<<" "<<e<<endl;
        for (i=0;i<k;i++) {
            int t=pos[i];
            string s="";
            for (j=0;j<r[t].size();j++) {
                s+=r[t][j];
                if (!block[s]) break;
                s="";
            }
            if (j==r[t].size()) block[l[t]]=true;
        }
        //for (i=0;i<n;i++) if (block[l[i]]) cout<<l[i]<<" ";cout<<endl;
    }
    void getV()
    {
        int i,j;
        char c;
        for (i=0;i<n;i++) {
            for (j=0;j<r[i].size();j++)  {
                c=r[i][j];
                if (!isupper(c)) vt.insert(c);
            }
            c=l[i][0];
            vn.insert(c);
        }
        vt.delete_block();
        //for (i=0;i<vt.n;i++) cout<<vt.get(i)<<" "; cout<<endl;
        //for (i=0;i<vn.n;i++) cout<<vn.get(i)<<" "; cout<<endl;
    }
    Set First(string s)
    {
        int i,j;
        Set a;
        if (s=="$") { a.insert('$'); }
        else if (!isupper(s[0])) { a.insert(s[0]); }
        else {
            for (i=0;i<s.size();i++) {
                if (first[s[i]].n>0) {
                    a.And(first[s[i]]);
                    string str=""; str+=s[i];  // 验证当前非终结符str能否推出空产生式
                    if (!block[str]) break;
                }
                else break;
            }
        }
        return a;
    }
    Set Follow(char v)
    {
        int i,j,t,len;
        Set a;
        for (i=0;i<n;i++) {
            t=r[i].find(v,0),len=r[i].size();
            if (t<0) continue;
            else if (t==len-1) {
                a.And(follow[l[i][0]]) ;
            }
            else {
                Set b=First(r[i].substr(t+1,len-1));
                t=b.find('$');
                if (t>=0) a.And(follow[l[i][0]]);
                a.And(b);
            }
        }
        return a;
    }
    void getFirst()
    {
        int i,j;
        char c;
        string s;
        getblock();
        getV();
        for (i=0;i<vt.n;i++) {
            first[vt.get(i)].insert(vt.get(i)) ;
        }
        int cnt=0;
        do{
            cnt=0;
            for (i=0;i<n;i++) {
                int t=first[l[i][0]].n;
                first[l[i][0]].And(First(r[i]));
                if (t!=first[l[i][0]].n) cnt++;
            }
        }while(cnt);

        for (i=0;i<vn.n;i++) { cout<<vn.get(i)<<": "; first[vn.get(i)].show();  }
    }
    void getFollow()
    {
        int i,j;
        int cnt;
        follow[vn.get(0)].insert('#');  //  开始符的follow集初始化
        do {
            cnt=0;
            for (i=0;i<vn.n;i++) {
                int t=follow[vn.get(i)].n;
                follow[vn.get(i)].And(Follow(vn.get(i))) ;
                if (t!=follow[vn.get(i)].n) cnt++;   // follow增大
            }
        }while(cnt); // 当所有follow集不再增大时退出
        for (i=0;i<vn.n;i++) follow[vn.get(i)].delete_block();
        for (i=0;i<vn.n;i++) { cout<<vn.get(i)<<": "; follow[vn.get(i)].show();  }
    }
    void getSelect()
    {
        int t,i,j;
        for (int i=0;i<n;i++) {
            Set a=First(r[i]);
            t=a.find('$');
            select[i]=a;
            if (t>=0) {
                select[i].And(follow[l[i][0]]);
                select[i].delete_block();
            }
        }
        for (i=0;i<n;i++) { cout<<l[i]<<"->"<<r[i]<<":\t"; select[i].show();  }
    }
    void getTable()
    {
        int i,j;
        vt.insert('#');
        for (i=0;i<vn.n;i++) {
            for (j=0;j<vt.n;j++) {
                table[i][j]="0";
            }
        }

        for (i=0;i<n;i++) {
            int row=vn.find(l[i][0]);
            Set a=select[i];
            for (j=0;j<a.n;j++) {
                int col=vt.find(a.get(j));
                table[row][col]=r[i];
            }

        } cout<<"     ";
        for (i=0;i<vt.n;i++) cout<<vt.get(i)<<"\t";cout<<endl;
        for (i=0;i<vn.n;i++) { cout<<vn.get(i)<<"   ";
            for (j=0;j<vt.n;j++) {
                cout<<table[i][j]<<"\t";
            }cout<<endl;
        }
    }
    string print(stack<char> s)
    {
        stack<char> st;
        string str="";
        while(!s.empty()){
            st.push(s.top());
            s.pop();
        }
        while(!st.empty())
        {
            s.push(st.top());
            str+=st.top();
            st.pop();
        }
        return str;
    }
    void analyse(string word)
    {
        int i,j,k=0,cnt=1,len=word.size();
        stack<char> s,s_r;
        s.push('#');
        s.push(l[0][0]);
        //cout<<k<<"\t"<<print(s)<<"\t"<<word<<
        while(s.top()!='#')
        {
            char c=s.top();  //cout<<"top: "<<c<<endl;
            string str=table[vn.find(c)][vt.find(word[k])];
            if (str=="$") {
                cout<<cnt++<<"\t"<<print(s)<<"\t"<<word.substr(k,len-1)<<"\t"<<c<<"->"<<"$"<<endl;
                s.pop();

                continue;
            }
            if (!isupper(c)) {
                if (c==word[k]) {
                    cout<<cnt++<<"\t"<<print(s)<<"\t"<<word.substr(k,len-1)<<"\t"<<c<<"匹配"<<endl;
                    k++;
                    s.pop();


                }
                else {
                    puts("-------------------------------------------------");
                    puts("error word!");
                    exit(1);
                }
            }
            else {
                //string str=table[vn.find(c)][vt.find(word[k])];
                cout<<cnt++<<"\t"<<print(s)<<"\t"<<word.substr(k,len-1)<<"\t"<<c<<"->"<<str<<endl;
                s.pop();
                for (i=str.size()-1;i>=0;i--) {
                    s.push(str[i]);
                }
            }
        }

        if (s.top()=='#' && k==word.size()-1) {
            cout<<cnt++<<"\t"<<print(s)<<"\t"<<word.substr(k,len-1)<<"\t"<<"接受"<<endl;
            puts("-------------------------------------------------");
            puts("accept!");
        }
        else  {
            puts("-------------------------------------------------");
            puts("error word");
        }
    }
};
void split(string s,LL1 &a,int &k)
{
    int t=s.find("->",0);
    string l=s.substr(0,t);
    string r=s.erase(0,t+2);
    for (int i=0;1;i++) {
        t=r.find("|",0);
        if (t>=0) {
            a.l[k]=l;
            a.r[k++]=r.substr(0,t);
            r=r.erase(0,t+1);
        }
        else break;
    }
    a.l[k]=l;
    a.r[k++]=r;
    //cout<<a<<" "<<b<<endl;
}

int main()
{
    int i,j;
    string grammer[N];
    LL1 a;
    printf("please input the grammer(end by 0):\n");
    for (i=0;1;i++) {
        cin>>grammer[i];
        if (grammer[i]=="0") break;
        split(grammer[i],a,a.n);
        //cout<<l[i]<<"->"<<r[i]<<endl;
    }
    for (int i=0;i<a.n;i++) cout<<a.l[i]<<"\t"<<a.r[i]<<endl; cout<<endl;
    puts("-------First--------");
    a.getFirst();
    puts("--------------------\n");
    puts("-------Follow--------");
    a.getFollow();
    puts("--------------------\n");
    puts("-------Select--------");
    a.getSelect();
    puts("--------------------\n");
    puts("-------Talbe--------");
    a.getTable();
    puts("--------------------\n");
    string word;


    while(cin>>word) {
        puts("please input the word to analyse(end by #) :\n");
        puts("-------------------------------------------------");
        a.analyse(word);
        cout<<endl;
    }


}

/*
S->1111|3333
B->2222|4444
C->123|456|789|$
D->AAA|$
A->$
0
E->TR
R->+TR|$
T->FW
W->*FW|$
F->i|(E)
0
i+i*i#
*/




















