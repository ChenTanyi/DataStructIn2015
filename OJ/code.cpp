#include <iostream>
#include <cstring>

using namespace std;

const int N = 200 + 10, M = 128 + 2;

typedef long long LL;

template <class T>
class stack
{
		public:
				int cnt;
				T arr[N];
				stack() : cnt(0) { }
				bool empty() { return cnt == 0; }
				T top() { if(!empty()) return arr[cnt - 1]; }
				T pop() { if(!empty()) return arr[--cnt]; }
				void push(const T &r) { arr[cnt++] = r; }
				int size() { return cnt; }
}; 
stack<char> opt;
stack<LL> opr;
bool isError = false;
int order[M];

bool isNum(char x)
{
		if(x <= '9' && x >= '0')
				return true;
		return false;
}

LL getNum(string::iterator &s)
{
		LL x = 0;
		while(isNum(*s))
		{
				x = x * 10 + (*s) - '0';
				++s;
		}
		return x;
}

LL power(LL base, LL p)
{
		LL x = base, ans = 1;
		while(p)
		{
				if(p & 1) ans *= x;
				x *= x, p >>= 1;
		}
		return ans;
}

bool evaluate()
{
		char op = opt.pop();
		LL left, right;
		if(!opr.empty()) right = opr.pop();
		else { isError = true; return false; }
		if(op == '$') { opr.push((-1) * right); return true; }
		if(!opr.empty()) left = opr.pop();
		else { isError = true; return false; }
		if(op == '+')
				opr.push(left + right);
		else if(op == '-')
				opr.push(left - right);
		else if(op == '*')
				opr.push(left * right);
		else if(op == '/')
		{
				if(right == 0) { isError = true; return false; }
				opr.push(left / right);
		}
		else if(op == '^')
				opr.push(power(left, right));
		else { isError = true; return false; }
		return true;
}

int main()
{
		bool NeedOpt = false;
		order['+'] = order['-'] = 1;
		order['*'] = order['/'] = 2;
		order['^'] = 3;
		order['$'] = 4;

		string s = "", tmp;
		getline(cin, tmp);
		for(int i = 0; i < tmp.length(); ++i)
				if(tmp[i] != ' ')
						s += tmp[i];
		string::iterator str = s.begin();


		while(str != s.end())
		{
				if(isError) break;
				if(isNum(*str))
						opr.push(getNum(str)), NeedOpt = true;
				else
				{
						if(!NeedOpt && *str == '-')
								opt.push('$'), NeedOpt = true, ++str;
						else if(*str == ')')
						{
								// evaluate until '(' appears
								++str;
								while(!opt.empty() && opt.top() != '(')
										if(!evaluate())
												break;
								if(opt.empty()) { isError = true; break; }
								else opt.pop();
								NeedOpt = true;
						}
						else // *str == +-*/^(
						{
								// if order[cur] > order[top] then push
								// else evaluate
								// note that ^ is right-associated
								if(*str == '(')
										opt.push(*str);
								else
								{
										while(!opt.empty() && opt.top() != '(' && order[opt.top()] >= order[*str])
												if(!evaluate())
														break;
										opt.push(*str);
								}
								++str;
								NeedOpt = false;
						}
				}
		}
		while(!opt.empty())
				if(!evaluate())
						break;

		if(isError)
				cout << "Error" << endl;
		else
				cout << opr.top() << endl;
}
