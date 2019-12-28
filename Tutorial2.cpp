#include<iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;

bool isPrime(int n)
{
    if(n == 1) {
            return false;          
    }

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
void show_array(int array[],int size) {
	for(int i=0;i<size;i++) {
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

int main() {

	int m;
	int n;

	srand((unsigned)time(0));

	cout<<"2)"<<endl;

	cout<<"give input m:";
	cin>>m;

	cout<<"give input n:";
	cin>>n;

	int prime = 2;

	int a[m];//generate array first m prime numbers increasing order
	int b[n];//first is 1 ,last is largerst array a

	for(int i=0;i<m;i++) {
		a[i] = prime;
		prime = findNextPrime(prime);
	}
	b[0]=1;
	for(int i=1;i<n;i++) {
		b[i] = (rand()%a[m-1])+1;
	}
	cout<<"a:";
	show_array(a,m);
	cout<<"b:";
	show_array(b,n);

	int count = 0;

	for(int i=0;i<n;i++) {
		if(isPrime(b[i])) {
			count++;
		}
	}
	cout<<"number of primes in b:"<<count<<endl;
	return 0;
}
