#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h> 
using namespace std;
typedef struct node node;

struct node{
    string str="";
    struct node *left = NULL;
    struct node *right= NULL;
};


string dectobin(int n)
{
    string s="";
    int num = n;
    int bin=0;
    for(int i=0;i<6;i++)
    {
        bin = num % 2;
        string temp="";
        temp =to_string(bin);
        s=s+temp;
        num /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}


void constructhufftree(vector<pair<string,string>> codes,node *root)
{
    for (int i=0;i<codes.size();i++)
    {
        string temp = codes[i].second;
        int len = temp.length();
        node *head = root;
        for(int j=0;j<len;j++)
        {
            if(temp[j] == '0')
            {   
                if (head->left == NULL)
                {
                    node *Node = new node;
                    head->left = Node;
                }
                
                head = head->left;
            }
            if(temp[j] == '1')
            {   
                if (head->right == NULL)
                {
                    node *Node = new node;
                    head->right = Node;
                }
                head = head->right;
            }
        }
        head->str = codes[i].first;
    }
}

int main() {
    string temp;
    getline(cin,temp);
    int t;
    t = stoi(temp);
    for (int i=0; i<t; i++)
    {
        int n,lastbits;
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);
        n = stoi(s1);
        lastbits = stoi(s2);
        vector<pair<string,string>> codes;
        for (int j=0;j<n;j++)
        {
            string t1,t2="";
            getline(cin,t1);
            string t3="";
            t3 = (char) t1[0];
            for (int z=2;z<t1.length();z++)
            {
                t2+=t1[z];
            }
            codes.push_back(make_pair(t3,t2));
        }
        
        string input;
        getline(cin,input);
        //cout << input << endl;
        string binary="";
        for(int j=0;j<input.length();j++)
        {
            //cout << input[j];
            binary += dectobin(int(input[j])-48);
            //cout << j <<" "<<binary << endl; 
        }
        //cout << "extra" << lastbits << endl;
        //cout << binary << endl;
        if (lastbits != 0)
        {
        binary.erase(binary.end()-(6-lastbits),binary.end());
        }
        //cout << binary << endl;
        node *root = new node;
        //cout << root->str << " " << root->left << "  " << root->right<<endl;
        constructhufftree(codes,root);
        //cout << root->left->left->str << "~" << root->left->right->str << "~"<< root->right->left->str<< "~" <<                                    root->right->right->str << "~" <<endl;
        string ans="";
        node *temp4 = root;
        for (int k=0;k<binary.length();k++)
        {
            if (binary[k]=='0')
            {
                temp4 = temp4->left;
                if (temp4->left == NULL && temp4->right ==NULL)
                {
                    ans += temp4->str;
                    temp4 = root;
                }
                // else
                // {
                //     k++;
                // }
            }
            
            if (binary[k]=='1')
            {
                temp4 = temp4->right;
                if (temp4->left == NULL && temp4->right ==NULL)
                {
                    ans += temp4->str;
                    temp4 =root;
                } 
                // else
                // {
                //     k++;
                // }
            }
        }
        cout << ans << endl;
        
        
    }
    return 0;
}
