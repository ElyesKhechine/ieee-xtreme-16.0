#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

unsigned int vectsum(vector <unsigned int> j){
	unsigned int sum=0;
	for(int k=0;k<(int)j.size();k++){
	    sum+=j[k];
	}
	return sum;
}


int imaxvect(vector <unsigned int> t){
	int imax=0;
	for(int i=0; i<(int) t.size();i++){
		if (t[i]>t[imax])
			imax=i;
	}
	return imax;
}
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    vector <unsigned int> j;
    unsigned int x;
    for(int i=0;i<n;i++){
        cin >> x;
        j.push_back(pow(2,x));
    }
    unsigned int imax=0;
    unsigned int time=0;
    unsigned int sum=0;
    unsigned int prmax=0;
    if (m>=n){
    	time = j[imax];
	}
	else if (m==1){
		time=vectsum(j);
	}
	else{
		//worker 1 => max value
		//worker 2 => next max
		//...
		//worker m => sum of the rest of the table
		for(int i=1;i<=m;i++){
			imax=imaxvect(j);
			if (i==1){
				prmax=j[imax];
				time=prmax;
			}
			if(i==m){
				if (vectsum(j)>prmax)
					time=sum;
			}
			j[imax]=0;
		}
	}
	cout << time % ((int)pow(10,9)+7);
    return 0;
}
