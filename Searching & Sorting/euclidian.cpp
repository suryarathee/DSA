#include<iostream>
using namespace std;
int gcd(int a,int b){
    if(b==0) return -1;
    if(b>a){
        return gcd(b,a);
    }
    while(b!=0)
    {
        int reminder  = a%b;
        a=b;
        b=reminder;
    }
    return a;
}
int LCM(int a,int b){
    int gcdValue = gcd(a,b);
    return (a*b)/gcdValue;
}
int main(){
    int a,b;
    cout<<"Enter first numbers: ";
    cin>>a;
    cout<<"Enter second number ";
    cin>>b;
    cout<<"LCM of "<<a<<" and "<<b<<" is "<<LCM(a,b)<<endl;
    cout<<"HDF of "<<a<<" and "<<b<<" is "<<gcd(a,b)<<endl;
    return 0;
}