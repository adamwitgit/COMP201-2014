#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
	string token;
	int x, left, right;
	vector <int> stack;
	char *end;

	cout << "Enter in what you would like calculated in Reverse Polish Notation: " << endl;
	while (cin >> token)
	{
		if (token == "+")
		{
			left = stack.back();
			stack.pop_back();
			right = stack.back();
			stack.pop_back();
			stack.push_back(right+left);
		}
		else if (token == "-")
		{
			left = stack.back();
			stack.pop_back();
			right = stack.back();
			stack.pop_back();
			stack.push_back(right-left);
		}
		else if (token == "*")
		{
			left = stack.back();
			stack.pop_back();
			right = stack.back();
			stack.pop_back();
			stack.push_back(right*left);
		}
		else if (token == "/")
		{
			left = stack.back();
			stack.pop_back();
			right = stack.back();
			stack.pop_back();
			stack.push_back(right/left);
		}
		else if (token == ".")
		{
			break;
		}
		else
		{
			// must be a number
			x = strtol(token.c_str(), &end, 10);
			stack.push_back(x);
		}
	}

	for (int i = 0; i < stack.size(); i++)
	{
		cout << stack[i] << endl;
	}

	return 0;
}