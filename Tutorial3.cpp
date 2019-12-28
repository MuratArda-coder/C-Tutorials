#include<iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;

void sort_array(int array[],int size) {
	int max;
	int tmp;
	for(int i=0;i<size;i++) {
		max=i;
		for(int j=i;j<size;j++) {
			if(array[max]<array[j])
				max=j;
				tmp=array[i];
		}
		array[i]=array[max];
		array[max]=tmp;
		max=0;
	}
}

void show_array(int array[],int size) {
	for(int i=0;i<size;i++) {
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

int main() {

	cout<<"3)"<<endl;

	int m;//Student
	int n;//Exam
	int k;//K'th best Grade

	srand((unsigned)time(0));

	cout<<"give input m:";
	cin>>m;

	cout<<"give input n:";
	cin>>n;

	

	int array[m][n];

	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			array[i][j] = (rand()%100)+1;
		}
	}
	cout<<"array:"<<endl;
	
	for (int i = 0; i < m; i++) { 
        	for (int j = 0; j < n; j++) {  
			cout << array[i][j]<<" "; 
		}
		cout<<endl;
	}

	cout<<endl;
	cout<<"give input k:";
	cin>>k;
	cout<<endl;
	int kArray[m][k];
	int tmpArray[n];

	if(k>n) {
		cout<<"invalid input!!!"<<endl;
	}
	else {

		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				tmpArray[j] = array[i][j];
			}

			sort_array(tmpArray,n);

			for(int j=0;j<k;j++) {
				kArray[i][j] = tmpArray[j];
			}
		}

		cout<<"K'th best Grade for each student"<<endl;
		for (int i = 0; i < m; i++) { 
        		for (int j = 0; j < k; j++) {  
				cout << kArray[i][j]<<" "; 
		}
		cout<<endl;
		}
	}


	return 0;
}
