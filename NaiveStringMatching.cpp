#include <bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;

int stringMatching(int n, int m, string text, string pattern){
	for(int s = 0; s <= n - m; s++){
     	int i = 1;
     	int j = 1;
     	while(j <= m && text[s+i] == pattern[j]){
         	i++;
         	j++;
     	}
     	if(j == m){
         	return s;
     	}
	}
	return -1;

}

int main()
{
	string text;
	string pattern;
	cout << "enter the text: " << endl;
	cin >> text;
	cout << "enter the pattern: " << endl;
	cin >> pattern;
    
	int n = text.length();
	int m = pattern.length();
    
	int value = stringMatching(n, m, text, pattern);
	cout << "pattern occurs with " << value << endl;
    

	return 0;
}
