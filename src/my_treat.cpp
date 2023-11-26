#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include<bits/stdc++.h>
#include <algorithm>
#include <sstream>


using namespace std;
int min_meals(vector <int> t){
    int min=-1000000;
    for(int i=0;i<(int)t.size();i++){
        if (t[i]<min)
            min=t[i];
    }
    return min;
}
int min_days(vector <int> t){
    int min=0;
    for(int i=0;i<(int)t.size();i++){
        if (t[i]>0)
            min++;
    }
    return min;
}
int findname(vector <string> v, string K){
	std::vector<string>::iterator it;
	it = find(v.begin(), v.end(), K);
  
    // If element was found
    if (it != v.end()) 
    {
        // calculating the index
        // of K
        return it - v.begin();
    }
    else {
        // If the element is not
        // present in the vector
        return -1;
    }
}
void extract(istringstream iss, string giver, string receiver,int *n){
	/*while(i<43)
		if(i<20 && isalpha(str[i])){
			giver[i]=str[i];
			i++;
		}
		else if(isdigit(str[i]) && 20<=i<43){
		num[i]=str[i];
		
	}
	else if(isdigit(str[i])){
		num[i]=str[i];
	}*/
	//iss >> giver >> n >> receiver;
	//cout << giver << " " << n << " " << receiver << endl; 
}
void show(vector<string> people, vector <int> treats){
	for (int i=0;i<people.size();i++){
		cout << "people= ["<<i<<"]= "<<people[i]<<endl;
    	cout << "treats= ["<<i<<"]= "<<treats[i]<<endl;
	}
}

int main() {
    int t;
    cin >> t;
    int m,j,n,k,x,i;
    string giver;
    string receiver;
    string tmp;
	char e=' ';
    vector <string> people;
    vector <int> treats;
    for(i=0;i<t;i++){
        cin >> m;
        for(j=0;j<m;j++){  	
        	cin >> tmp;
			istringstream iss(tmp);
            iss >> giver >> n;
			cout << "giver= "<< giver << " " << n << endl; 
            x=findname(people,giver);
            if (x==-1) {
                  people.push_back(giver);
                  treats.push_back(n);
                  x=findname(people,giver);
            }
            else
                treats[x]+=n;
            for(k=0;k<=n;k++){
            	cin >> tmp;
                istringstream iss(tmp);
            	iss >> receiver;
				cout << "receiver= " << receiver << endl; 
                x=findname(people,receiver);
                if (x==-1) {
                   people.push_back(receiver);
                   treats.push_back(-1);
                   x=findname(people,receiver);
                }
                else
                    treats[x]-=1;
                cout << "i="<<i<<" j="<<j<<" k"<<k<<endl<<"t= "<<t<<" m= "<<m<<" n= "<<n<<endl<<"giver="<<giver<<"receiver="<<receiver<<endl;
            }
            show(people,treats);
        }
        cout << min_meals(treats) << " " << min_days(treats); 
    }
    
    return 0;
}
