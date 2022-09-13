#include <iostream>

using namespace std;

int main() 
{
#ifdef AUCA_DEBUG
    cout << "Author: Kobiljon Muhammadov" << endl;
#endif
    cout << "Hello, C++ " << __cplusplus << "!\n";
}