#include <iostream>
#include <string.h>
#include <ctype.h>
#include  <bits/stdc++.h>

using namespace std;

int main() {
    string ch;
    getline(cin,ch);
    int tmp;
    int i;
    for(i=0;ch[i]!='\0';i++){
    	if(!isalpha(ch[i])){
    		continue;
		}
        else{
        	tmp=int(ch[i])-12;
	        if(tmp<65)
	        	tmp=90-(11-(int(ch[i])-65));
	        else if(tmp>84 && tmp<97)
	        	tmp=122-(11-(int(ch[i])-97));
	        ch[i]=char(tmp);
		}
    }
    cout << ch;
    return 0;
}
