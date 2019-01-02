#include <iostream>
using namespace std;
void findnotoconseqone(int n)
{
    long *arr = new long[n];
    arr[0] = 2;
    arr[1] = 3;
    for (int i=2;i<n;i++)
    {
        arr[i] = (arr[i-1]%(1000000000+7))+(arr[i-2]%(1000000000+7));
        //cout << arr[i] << " " ;
    }
    //cout << endl;
    cout << arr[n-1]%(1000000000+7) << endl; 
    //cout << arr[n-1] % (10^9 ) << endl;
}


int main() {
	int q;
	cin >> q;
	for (int i=0;i<q;i++)
	{
	    int n;
	    cin >> n;
	    findnotoconseqone(n);
	}
	return 0;
}