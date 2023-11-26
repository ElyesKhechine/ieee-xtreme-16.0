#include <iostream>
#include <string.h>
#include  <bits/stdc++.h>
#include <map>


using namespace std;

char minuscule(char maj) // MAJUSCULE --> minuscule
{
	char min;
	min = (char)maj;
 	if((int)maj <= 90 && (int)maj >= 65) // majuscule
	{
		return (char)((int)min + 32);
	}
	else
	{
		if((int)maj <= 122 && (int)maj >= 97) // minuscule
		{
			return (char)min;
		}
		else
		{
			return maj; // ce n'est pas une lettre
		}
	}
}

void removeSpaces(string str)
{
    // To keep track of non-space character count
    int count = 0;
 
    // Traverse the given string. If current character
    // is not space, then place it at index 'count++'
    for (int i = 0; str[i]; i++)
        if (isalpha(str[i]))
            str[count++] = minuscule(str[i]); // here count is
                                   // incremented
    str[count] = '\0';
}

enum StringValue {		  lefthandhead,
                          lefthandhip,
                          lefthandstart,
                          leftlegin,
                          leftlegout,
                          righthandhead,
                          righthandhip,
                          righthandstart,
                          rightlegin,
                          rightlegout,
                          turn};                          
// Map to associate the strings with the enum values
static  map<string, StringValue> s_mapStringValues;

void Initialize()
{
    s_mapStringValues["left hand to head"]=lefthandhead;
    s_mapStringValues["left hand to hip"]=lefthandhip;
    s_mapStringValues["left hand to start"]=lefthandstart;
    s_mapStringValues["left leg in"]=leftlegin;
    s_mapStringValues["left leg out"]=leftlegout;
    s_mapStringValues["right hand to head"]=righthandhead;
    s_mapStringValues["right hand to hip"]=righthandhip;
    s_mapStringValues["right hand to start"]=righthandstart;
    s_mapStringValues["right leg in"]=rightlegin;
    s_mapStringValues["right leg out"]=rightlegout;
    s_mapStringValues["turn"]=turn;
}
void switcher (char *c){
	switch(*c){
		case '(':
			*c=')';
		break;
		case ')':
			*c='(';
		break;
		case '/':
			*c='\\';
		break;
		case '\\':
			*c='/';
		break;
		case '>':
			*c='<';
		break;
		case '<':
			*c='>';
		break;
	}
}

void permute(char *a, char *b){
	switcher(a);
	switcher(b);
	char tmp=*a;
	*a=*b;
	*b=tmp;
}

int main() {
    Initialize();
    int t;
    cin >> t;
    string man;
    string ch;
    int i=0,j=0;
    for(i=1; i<=t; i++){
        man = " o \n/|\\\n/ \\\n";
        bool direction=true;
        int d;
        cin >> d;
        for(j=1;j<=(d+1);j++){
        	//cout << "direction = " << direction << endl ;
            getline(cin,ch);
            removeSpaces(ch);
            size_t found=ch.find("say");
            if (found != string::npos){
                string r = ch.substr((int)found+4,ch.length()-3-(ch.length()-80));
                cout << r << endl;
            }
            else if(j!=1){
                switch(direction){
                    case true:
                        switch(s_mapStringValues[ch]){
                            case lefthandhead:
                                man[2]=')';
                                man[6]=' ';
                                cout << man;
                            break;
                            case lefthandhip:
                                man[6]='>';
                                man[2]=' ';
                                cout << man;
                            break;
                            case lefthandstart:
                                man[6]='\\';
                                man[2]=' ';
                                cout << man;
                            break;
                            case leftlegin:
                                if (man[8]!='<')
                                    man[10]='>';
                                cout << man;
                            break;
                            case leftlegout:
                                man[10]='\\';
                                cout << man;
                            break;
                            case righthandhead:
                                man[0]='(';
                                man[4]=' ';
                                cout << man;
                            break;
                            case righthandhip:
                                man[4]='<';
                                man[0]=' ';
                                cout << man;
                            break;
                            case righthandstart:
                                man[4]='/';
                                man[0]=' ';
                                cout << man;
                            break;
                            case rightlegin:
                                if (man[10]!='>')
                                    man[8]='<';
                                cout << man;
                            break;
                            case rightlegout:
                                man[8]='/';
                                cout << man;
                            break;
                            case turn:
                                permute(&man[0],&man[2]);
                                permute(&man[4],&man[6]);
                                permute(&man[8],&man[10]);
                                cout << man;
                                direction=!direction;
                            break;
                            }
                    break;
                    case false:
                        switch(s_mapStringValues[ch]){
                            case righthandhead:
                                man[2]=')';
                                man[6]=' ';
                                cout << man;
                            break;
                            case righthandhip:
                                man[6]='>';
                                man[2]=' ';
                                cout << man;
                            break;
                            
                            case righthandstart:
                                man[6]='\\';
                                man[2]=' ';
                                cout << man;
                            break;
                            case rightlegin:
                                if (man[8]!='<')
                                    man[10]='>';
                                cout << man;
                            break;
                            case rightlegout:
                                man[10]='\\';
                                cout << man;
                            break;
                            case lefthandhead:
                                man[0]='(';
                                man[4]=' ';
                                cout << man;
                            break;
                            case lefthandhip:
                                man[4]='<';
                                man[0]=' ';
                                cout << man;
                            break;
                            case lefthandstart:
                                man[4]='/';
                                man[0]=' ';
                                cout << man;
                            break;
                            case leftlegin:
                                if (man[10]!='>')
                                    man[8]='<';
                                cout << man;
                            break;
                            case leftlegout:
                                man[8]='/';
                                cout << man;
                            break;
                            case turn:
                                permute(&man[0],&man[2]);
                                permute(&man[4],&man[6]);
                                permute(&man[8],&man[10]);
                                cout << man;
                                direction=!direction;
                            break;
                            }
                    break;
                    
                }
            }
            if(j==d+1){
                man = " o \n/|\\\n/ \\\n";
            }
        }
    }
    return 0;
}

