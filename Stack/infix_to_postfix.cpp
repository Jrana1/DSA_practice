#include <bits/stdc++.h>
using namespace std;

int get_prec(char c)
{

    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (isalpha(c) || isdigit(c))
        return 3;
}
/// Method 1
string infix_to_postfix(string str)
{

    string ans;
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {

        if (isalpha(str[i]) || isdigit(str[i]))
        {

            ans += str[i];
        }
        else
        {

            if (st.empty())
            {
                st.push(str[i]);
            }
            else if (get_prec(str[i]) > get_prec(st.top()))
            {
                st.push(str[i]);
            }
            else
            {
                while (!st.empty() && get_prec(str[i]) <= get_prec(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(str[i]);
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

/// Method 2

string infix_to_postfix2(string str)
{

    stack<char> st;
    string ans;

    for (int i = 0; i < str.length(); i++)
    {

        if (st.empty())
        {
            st.push(str[i]);
        }
        else
        {

            if (get_prec(str[i]) > get_prec(st.top()))
            {
                st.push(str[i]);
            }
            else
            {
                while (!st.empty() && get_prec(str[i]) <= get_prec(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(str[i]);
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

string infix_to_postfix3(string s)
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

                ans += st.top(),
                    st.pop();
                i--;
            }
        }
    }
    while (!st.empty())
    {
        ans += st.top(),
            st.pop();
    }
    return ans;
}
int main()
{
    string s = "a^2+2*(a*b)+b^2";

    cout << infix_to_postfix3(s) << endl;
    return 0;
}