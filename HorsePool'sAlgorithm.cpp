#include <bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;
//shift table used to do string matching
int printShift(string pattern, string text){
	int m = pattern.length();
	int n = text.length();
	vector<int>  shift(26);
    
	for(int i = 0; i < 26; i++){
    	shift[i] = m;
	}
	for(int i = 0; i <= m- 2; i++){
    	if(pattern[i] == '_'){
        	shift[pattern[i]] = 6;
        	continue;
    	}
    	shift[pattern[i] - 'a'] = m - 1 - i;
	}
    
	int j = -1;
	while(j + m <= n){
    	if(pattern[m-1] == text[j + m - 1]){
        	int i = m - 2;
        	while(i >= 0 && pattern[i] == text[j+i]){//comparing all characters in the window
            	i--;
        	}
        	if(i == -1){
            	return j;
        	}
    	}
    	j = j + shift[text[j + m - 1] - 'a'];
	}
	return n;

}

int main()
{
   string text;
	string pattern;
	cout << "enter the text: " << endl;
	cin >> text;
   
	cout << "enter the pattern: " << endl;
	cin >> pattern;
   
    
	// int n = text.length();
	int m = pattern.length();
    
	int value = printShift(pattern, text);
	cout << value << endl;
    

	return 0;
}


