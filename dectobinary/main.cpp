
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
string dectobin(int n)
{
    string s="";
    int num = n;
    int bina=0;
    for(int i=0;i<8;i++)
    {
        bina = num % 2;
        string temp;
        stringstream ss;
        ss << bina;
        temp = ss.str();
        //temp = to_string(bina);
        cout << temp <<endl;
        s=s+temp;
        num /= 2;

    }
    reverse(s.begin(), s.end());

    cout << s;
    return s;
}

int main()
{
    string a = dectobin(5);
    cout<<a;

    return 0;
}


/*
for(int j=0;j<binary.length())
        {
            string temp3;
            temp3+=binary[j];
            for (int k=0;k<codes.size();k++)
            {
                if (temp3 == codes[k].second)
                {
                    ans+=codes[k].first;
                    break;
                }

            }
            j = j + temp3.length();

        }
*/
