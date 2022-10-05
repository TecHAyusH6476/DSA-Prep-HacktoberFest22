//Minimum Bracket Reversal
//For a given expression in the form of a string, find the minimum number of brackets that can be reversed 
//in order to make the expression balanced. The expression will only contain curly brackets.
//If the expression can't be balanced, return -1.


//Time Complexity - O(n)
//Space Complexity - O(n)

#include <bits/stdc++.h>
using namespace std;

int countBracketsReversal(string expression){
	//If the length of string is odd, then it can't be balanced.
	if(expression.length() % 2 != 0){
		return -1;
	}
	
	else{
		stack<char> s;
		
		int i = 0;
		
		while(expression[i] != NULL){
			
			if(expression[i] == '{'){
				s.push('{');
			}
			
			else if(expression[i] == '}' && s.empty()){
				s.push('}');
			}
			
			else if(expression[i] == '}' && ! s.empty()){
				if(s.top() == '{'){
					s.pop();
				}
				else{
					s.push('}');
				}
			}
			
			i++;
		}
		
		int count = 0;
		char c1 , c2;
		
		while(! s.empty()){
			c1 = s.top();
			s.pop();
			c2 = s.top();
			
			if(c1 == c2){
				count++;
			}
			else{
				count = count + 2;
			}
			
			s.pop();
		}
		
		return count;
	}
}

int main(){
	//Taking input
	string input;
	cin >> input;
	
	cout<<countBracketsReversal(input);
	
	return 0
}
