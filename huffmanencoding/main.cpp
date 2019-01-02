#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

typedef struct node node;

struct node{
    string str="";
    int freq=0;
    struct node *left = NULL;
    struct node *right= NULL;
};

struct node* newNode(string stri,int fre) 
{ 
  node* Node = new node;
  Node->str = stri; 
  Node->freq = fre;
  Node->left = NULL; 
  Node->right = NULL; 
  return Node ; 
}

void getfrequencies(string s,vector<pair<int,int>> &A)
{
    int count[128]={0};
    for (int i=0;i<s.length();i++)
    {
        //cout << int(s[i]) << endl;
        count[int(s[i])] += 1;
    }
    for (int j=0;j<128;j++)
    {
        if(count[j]!=0)
        {
            A.push_back(make_pair(j,count[j]));
            //cout << j << "-" << count[j] << endl;
        }  
    } 
}

struct my_comp{
    bool operator()(const node *x,const node *y)const  //min-heap
    {
        if (x->freq == y->freq)
        {
            return x->str > y->str;
        }
        return x->freq > y->freq;
    }
};

void gethuffcodes(node* t,string s,vector<pair<string,string>> &codes)
{
    if(t->left ==NULL && t->right ==NULL)
    {
        codes.push_back(make_pair(t->str,s));
    }
    if (t->left !=NULL)
    {
        //string s1 = s;
        //s.appendt->left->str = 
        gethuffcodes(t->left,s+"0",codes);
    }
    if (t->right !=NULL)
    {
        //string s1 = s;
        //s.appendt->left->str = 
        gethuffcodes(t->right,s+"1",codes);
    }
}

int binaryToDecimal(string s) 
{ 
    string num = s; 
    int decimal = 0; 
    int len = num.length(); 
    for (int i=0;i<len;i++) 
    { 
        if (num[i] == '1') 
        {
            decimal += pow(2,len-i-1);
        } 
    } 
    return decimal; 
} 

int main() {
    string temp;
    getline(cin,temp);
    int t;
    t = stoi(temp);
    for (int i=0; i<t; i++)
    {
        priority_queue<node*, deque <node*>, my_comp> hufftree;//min-heap
        string s;
        getline(cin , s);
        //cout << s <<endl;
        vector<pair<int,int>> A;
        //cout << "Siz" << A.size() << " " << codes.size()<< endl;
        
        getfrequencies(s,A);
        //cout << "After Siz" << A.size() << " ";// <<codes.size()<< endl;
        vector<pair<string,string>> codes;
        
        for (int j=0;j<A.size();j++)
        {
            string temp2;
            //cout << "j" << j<< endl;
            temp2 = (char) A[j].first;
            node* tem = newNode(temp2,A[j].second);
            //cout << temp2 << endl;
            hufftree.push(tem);
        }
        while(hufftree.size()>1)
        {
            node *x=hufftree.top();
            hufftree.pop();
            //cout << "popped1 " << x->str << endl;
            node *y= hufftree.top(); 
            hufftree.pop();
            //cout << "popped2 " << y->str << endl;
            node *combined = newNode(x->str+y->str,x->freq+y->freq);
            if (x->freq < y->freq)
            {
                combined->left = x;
                combined->right = y;
            }
            else if (x->freq > y->freq)
            {
                combined->left = y;
                combined->right = x;
            }
            else if (x->freq == y->freq)
            {
                if(x->str < y->str )
                {
                    combined->left = x;
                    combined->right = y;
                }
                else
                {
                    combined->left = y;
                    combined->right = x;
                }
            }
            
            hufftree.push(combined);
            
        }
        gethuffcodes(hufftree.top(),"",codes);
//         for (int k=0;k<codes.size();k++)
//         {
//             cout << codes[k].first<< "-->" << codes[k].second<< endl;
//         }
        
        string binary=""; 
        for (int q=0;q<s.length();q++)
        {
            string present;
            for (int z=0;z<codes.size();z++)
            {
                string temp3;
                temp3 = (char) s[q];
            
                if (temp3 == codes[z].first)
                {
                    present =  codes[z].second;
                    break;
                }
            }
            binary = binary + present;
        }
        //cout  << binary.length() << endl;
        int temp4 = binary.length()%6;
        if (temp4 != 0)
        {
            string temp5 = "";
            for (int x=0;x<6-temp4;x++)
            {
                temp5=temp5 + "0";
            }
            binary = binary + temp5;
        }
        //cout  << binary.length() << endl;
        string ans="";
        for (int q=0;q<binary.length();q+=6)
        {
            string temp6 = "";
            for (int z=0;z<6;z++)
            {
                temp6 += binary[q+z];
            }
            int digit6 = binaryToDecimal(temp6);
            ans = ans + char(digit6+48);
        }
        cout << ans << endl;
    }
    return 0;
}
