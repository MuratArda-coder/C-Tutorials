#include<iostream>
using namespace std;

bool isPrime(int n)
{
    
    for (int i = 2; i <= n/2; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int findNextPrime(int n)
{
    int nextPrime = n;
    bool found = false;


    while (!found)
    {
        nextPrime++;
        if (isPrime(nextPrime))
            found = true;
    }

    return nextPrime;
}

int findLCM(int a,int b) {

	int primary_Num = 2;
	int LCM = 1;
	
	while(a!=1 || b!=1) {
		if(a%primary_Num==0 && b%primary_Num==0) {
			a = a/primary_Num;
			b = b/primary_Num;
			LCM = LCM*primary_Num;
		}
		else if(a%primary_Num==0) {
			a = a/primary_Num;
			LCM = LCM*primary_Num;
		}
		else if(b%primary_Num==0) {
			b = b/primary_Num;
			LCM = LCM*primary_Num;
		}
		else {
			primary_Num = findNextPrime(primary_Num);
		}
	}
	return LCM;

}

int main() {

	int a;
	int b;
	cout<<"1)Find LCSM"<<endl;

	cout<<"give input a:";
	cin>>a;

	cout<<"give input b:";
	cin>>b;

	if(a<0 || b<0)
		cout<<"invalid input";
	else
		cout<<findLCM(a,b)<<endl;

	return 0;
}
