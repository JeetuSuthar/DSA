#include <iostream>
using namespace std;

int fun(int i, int n) {
    // Base case: if i exceeds n, return 0 (indicating end of recursion)
    if (i > n) return 0;
    
    cout << i << endl;  // Print the current number
    return fun(i + 1, n);  // Recursive call and return the result of next recursion
}

int main() {
    int n;
    cin >> n;

    fun(1, n);  // Start the recursion from 1 to n

    return 0;
}


WE CAN ALSO DO USING VOID FUNCTION LIKE THIS 
#include <iostream>
using namespace std;

void fun(int i, int n) {
    // Base case: if i exceeds n, return 0 (indicating end of recursion)
    if (i > n) return ;
    
    cout << i << endl;  // Print the current number
     fun(i + 1, n);  // Recursive call and return the result of next recursion
}

int main() {
    int n;
    cin >> n;

    fun(1, n);  // Start the recursion from 1 to n

    return 0;
}
