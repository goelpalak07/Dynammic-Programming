#include<iostream>
using namespace std;
string str;
int LPS(int i,int j)
{
    if(i>j)
        return 0;
    if(i==j)
        return 1;
    if(str[i]==str[j])
        return LPS(i+1,j-1)+2;
    else
        return max(LPS(i+1,j),LPS(i,j-1));
}
int main()
{
    cout<<"Enter the string : ";
    cin>>str;
    cout<<"The length of Longest Palindromic Subsequence of "<<str<<" is : "<<LPS(0,str.size()-1)<<endl;
    return 0;
}
