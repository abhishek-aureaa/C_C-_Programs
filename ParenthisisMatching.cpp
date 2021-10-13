#include<iostream>

using namespace std;

#include <stdio.h>
#include <math.h>

/*Whats up! */
using namespace std;

#include<stack>

bool isPair(char op, char cl)
{
	if (op == '(' && cl == ')') return true;
	else if (op == '{' && cl == '}') return true;
	else if (op == '[' && cl == ']') return true;
	return false;
}

string isBalanced(string s) {

	stack<char>  stk;
	int len = s.length();
	if (!len)
		return "false";

	for (int i = 0;i < len;i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			stk.push(s[i]);
		else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
		{
			if (stk.empty() || !isPair(stk.top(), s[i]))
			{
				return "false";
			}
			else
				stk.pop();
		}
	}
	return stk.empty() ? "true" : "false";
}




int main()
{

	cout << isBalanced("") << "\n";
	cout << isBalanced(")(") << "\n";
	cout << isBalanced("([)]") << "\n";
	cout << isBalanced("{(a[])") << "\n";
	cout << isBalanced("(c]") << "\n";
	cout << isBalanced("((b)") << "\n";
	cout << isBalanced("[(") << "\n";

	cout << isBalanced("f(e(d))") << "\n";

	cout << isBalanced("(a)") << "\n";

	return 0;
}
