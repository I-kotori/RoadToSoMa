#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int N;
	cin >> N;
	double avg;
	double sum = 0;
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		sum += num;
	}
	avg = sum / N;
	cout << fixed << setprecision(2) << avg; 
	return 0;
}
