#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main(void)
{
    string str("HI THIS IS BRAIN");
    string *stringPTR = &str;
    string &stringREF = str;

    cout << "Memory address:" << endl;
    cout << "Str: " << &str << endl;
    cout << "Ptr: " << stringPTR << endl;
    cout << "Ref: " << &stringREF << endl;

    cout << "-----------------" << endl;

    cout << "Value:" << endl;
    cout << "Str: " << str << endl;
    cout << "Ptr: " << *stringPTR << endl;
    cout << "Ref: " << stringREF << endl;
}