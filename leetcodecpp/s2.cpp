#include "pch.h"

using namespace std;

int evalRPN(vector<string> &tokens) {
	stack<string>* s = new stack<string>;
	int ret = 0;
	if (tokens.size() == 1) {
		return atoi(tokens[0].c_str());
	}
	for (int i = 0; i <= tokens.size(); i++) {
		if (s->empty()) {
			s->push(tokens[i]);
			continue;
		}
		if (s->top() == "+") {
			s->pop();
			int num2 = atoi(s->top().c_str());
			s->pop();
			int num1 = atoi(s->top().c_str());
			s->pop();
			ret = num1 + num2;
			string ss = to_string(ret);
			s->push(ss);
		}
		else if (s->top() == "-") {
			s->pop();
			int num2 = atoi(s->top().c_str());
			s->pop();
			int num1 = atoi(s->top().c_str());
			s->pop();
			ret = num1 - num2;
			string ss = to_string(ret);
			s->push(ss);
		}
		else if (s->top() == "*") {
			s->pop();
			int num2 = atoi(s->top().c_str());
			s->pop();
			int num1 = atoi(s->top().c_str());
			s->pop();
			ret = num1 * num2;
			string ss = to_string(ret);
			s->push(ss);
		}
		else if (s->top() == "/") {
			s->pop();
			int num2 = atoi(s->top().c_str());
			s->pop();
			int num1 = atoi(s->top().c_str());
			s->pop();
			ret = num1 / num2;
			string ss = to_string(ret);
			s->push(ss);
		}
		if (i != tokens.size())
			s->push(tokens[i]);
	}

	return ret;
}

int main() {
	vector<string> tokens = { "2", "1", "+", "3", "*" };
	int ret = evalRPN(tokens);
	cout << "ret:" << ret << endl;

	return 0;
}