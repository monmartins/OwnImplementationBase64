#include <iostream>
#include "Base64.h"

using namespace std;
using namespace Base64;

int main(int argc, char** argv)
{
    string test = "teste 123";
   string result = EncryptB64(test);
   cout << "result " << result << endl;
    cout << DecryptB64(result) << endl;
    return 0;
}

