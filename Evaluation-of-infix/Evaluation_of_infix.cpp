#include<iostream>
#include<sstream>
#include<string>
#include<stack>
#include<cmath>
using namespace std;
int value(char c)
{
    if(c=='+'||c=='-')
        return 1;
    if(c=='*'||c=='/')
        return 2;
    if(c=='^')
        return 3;
    if(c=='('||c==')')
        return 4;
}
string eval(string x,string y,char op)
{
    stringstream as(x);
    int a=0;
    as>>a;
    stringstream bs(y);
    int b=0;
    bs>>b;
    if(op=='^')
    {
        int c=pow(b,a);
        ostringstream str1;
        str1<<c;
        return(str1.str());
    }
    else if(op=='/')
    {
        int c=b/a;
        ostringstream str1;
        str1<<c;
        return(str1.str());
    }
    else if(op=='*')
    {
        int c=b*a;
        ostringstream str1;
        str1<<c;
        return(str1.str());
    }
    else if(op=='+')
    {
        int c=b+a;
        ostringstream str1;
        str1<<c;
        return(str1.str());
    }
    else if(op=='-')
    {
        int c=b-a;
        ostringstream str1;
        str1<<c;
        return(str1.str());
    }
    return "";
}
int main()
{
    string infix;
    cout<<"Enter infix expression to evaluate"<<endl;
    cin>>infix;
    /*Conversion from infix to postfix*/
    string postfix="";
    stack<char>in;
    for(int i=0;i<infix.length();i++)
    {
        if(infix[i]>=48&&infix[i]<=57)
            postfix+=infix[i];
        else
        {
            if(in.empty())
                in.push(infix[i]);
            else if(infix[i]==')')
            {
                while(in.top()!='(')
                {
                    postfix+=in.top();
                    in.pop();
                }
                in.pop();
            }
            else
            {
                while((value(infix[i])<=value(in.top()))&&(!in.empty())&&value(in.top()!='('))
                    {
                        postfix+=in.top();
                        in.pop();
                        if(in.empty())
                            break;
                    }
                in.push(infix[i]);
            }

        }
    }
    while(!in.empty())
        {
            postfix+=in.top();
            in.pop();
        }
    cout<<"Postfix :"<<postfix<<endl;
    /*Evaluation of postfix*/
    stack<string>post;
    for(int i=0;i<postfix.length();i++)
    {
        if(postfix[i]>=48&&postfix[i]<=57)
        {
            post.push(postfix.substr(i,1));
        }
        else
        {
            string a=post.top();
            post.pop();
            string b=post.top();
            post.pop();
            char op=postfix[i];
            post.push(eval(a,b,op));
        }
    }
    cout<<"Result :"<<post.top()<<endl;
    return 0;
}
