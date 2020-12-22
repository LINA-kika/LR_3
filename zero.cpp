#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>


int main()
{
    
    int i=0;
    std::string infix;
    std::stack <char> st;
    std::queue <char> numbers;
    std::cout << "INPUT:" << std::endl;
    getline(std::cin, infix);
    std::cout << "Your input is " << infix  << std::endl;
    while(i<infix.size())
    {
       try
      {
        switch (infix.at(i))
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                numbers.push(infix.at(i));
                break;
           case '\\':   
             throw '\\';
            case '/':
            case '+':
            case '-':
            case '*':

            if(infix.at(i)=='/'&&infix.at(i+1)=='0')
                {
                    throw 0;
                }
            else if (st.empty()==true||st.top()=='(')
            {
                st.push(infix.at(i));
                numbers.push(' ');
                
            }
            else if (infix.at(i)<st.top())
            {
                st.push(infix.at(i));
                numbers.push(' ');
            }
            else if (infix.at(i)>=st.top())
            {
                while (st.top()<infix.at(i)||st.top()=='(')
                {
                    numbers.push(' ');
                    numbers.push(st.top());
                    st.pop();
                }
                st.push(infix.at(i));
               
            }
            break;
            case '(':
                
                numbers.push(' ');
                st.push(infix.at(i));
                break;
            case ')':
                while (st.top()!='(')
                {  
                    numbers.push(' ');
                    numbers.push(st.top());
                    st.pop();
                }
                st.pop();
                break;
            }
       }
       catch(int t)
            {
               std::cout << "ERROR!!! YOU ARE TRYING TO DEVIDE BY ZERO" << std::endl;
               return 0;
            }
        catch(char t)
            {
               std::cout << "INCORRECT SYMBOL" << std::endl;
               return 0;
            }
        i++;
        
    }
    while (!st.empty())
    {
        numbers.push(' ');
        numbers.push(st.top());
        st.pop();
    }
    while (!numbers.empty())
    {
        std::cout << numbers.front() << std::endl;
        numbers.pop();
    }
    return 0;
}