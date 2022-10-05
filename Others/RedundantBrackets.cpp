//For a given expression in the form of a string, find if there exist any redundant brackets or not.
//It is given that the expression contains only rounded parenthesis and the input expression will always be balanced and contains no spaces.
//A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.


//Check Redundant Brackets
//Time Complexity - O(n)
//Space Complexity - O(n)


#include <bits/stdc++.h>
using namespace std;

//Function to check redundant brackets
bool checkRedundantBrackets(string expression){
	if(expression[0] == 'NULL'){
		return false;
	}

	stack <char> s;
	
	for(int i = 0 ; i < expression.length() ; i++){
		if(expression[i] != ')'){
			s.push(expression[i]);
		}
		else{
			if(s.top() == '('){
				return true;
			}
			else{
				int count = 0;
				while(s.top() != '('){
					s.pop();
					count++;
				}
				s.pop();
				if(count <= 1){
				   return true;
				}
			}
		}
	}
	
	return false;
	
}

int main(){
	//Taking input 
	string input;
	cin >> input;
	
	cout<<((checkRedundantBrackets(input)) ? "true" : "false") << endl;
	
	return 0;
}
