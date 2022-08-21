#include <bits/stdc++.h>
using namespace std;
int prec_out_stack(char c)
{

    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 3;
    if (c == '^')
        return 6;
    if (c == '(')
        return 7;
    if (c == ')')
        return 0;
}
int prec_in_stack(char c)
{

    if (c == '+' || c == '-')
        return 2;
    if (c == '*' || c == '/')
        return 4;
    if (c == '^')
        return 5;
    if (c == '(')
        return 0;
}

string infix_to_postfix(string s)
{
    stack<char> st;
    string ans;

    for (int i = 0; i < s.length(); i++)
    {

        if (isalpha(s[i]) || isdigit(s[i]))
        {

            ans += s[i];
        }
        else
        {
            if (st.empty())
            {

                st.push(s[i]);
            }
            else if (prec_out_stack(s[i]) > prec_in_stack(st.top()))
            {
                st.push(s[i]);
            }
            else if (prec_out_stack(s[i]) == prec_in_stack(st.top()))
            {
                st.pop();
            }
            else
            {
                ans += st.top();
                st.pop();
                i--;
            }
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int calculation(int a, int b, char c)
{

    switch (c)
    {
    case '+':
        return (b) + (a);
        break;
    case '-':
        return (b) - (a);
        break;
    case '*':
        return (b) * (a);
        break;
    case '/':
        return (b) / (a);
        break;

    default:
        break;
    }
}
/// this is also a leed code question
int eva(vector<string> &tokens)
{
    stack<int> st;
    int num1, num2, op;

    for (int i = 0; i < tokens.size(); i++)
    {

        if (!(tokens[i].length() == 1 && !isalnum(tokens[i][0])))
        {
            st.push(stoi(tokens[i]));
        }
        else
        {
            num1 = st.top();
            st.pop();
            num2 = st.top();
            st.pop();
            // cout << tokens[i] << endl;
            st.push(calculation(num1, num2, tokens[i][0]));
        }
    }
    return st.top();
}
int main()
{
    // vector<string> ex = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    // cout << eva(ex);
    // string str = "abc";

    return 0;
}