#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to compute the greatest common divisor (GCD) using the Euclidean algorithm
    int gcd(int a, int b) {
        if (b == 0) return a; // Base case: if b is 0, GCD is a
        return gcd(b, a % b); // Recursive call with b and a % b
    }
    
    // Function to replace non-coprime adjacent elements in the array
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st; // Stack to store intermediate results
        
        // Iterate through each number in the input vector
        for (int num : nums) {
            st.push(num); // Push the current number onto the stack
            
            // While there are at least two elements on the stack
            while (st.size() > 1) {
                int top1 = st.top(); // Top element of the stack
                st.pop(); // Remove the top element
                int top2 = st.top(); // Next top element of the stack
                
                // Compute the GCD of the two top elements
                int g = gcd(top1, top2);
                
                // If the GCD is 1, they are coprime, push the top1 back and break
                if (g == 1) {
                    st.push(top1);
                    break;
                }
                
                // If the GCD is not 1, they are not coprime, combine them
                st.pop(); // Remove the second top element
                st.push(top1 / g * top2); // Push the combined element back onto the stack
            }
        }
        
        // Collect the elements from the stack into a vector
        vector<int> ans(st.size());
        int i = st.size()-1;
        while (!st.empty()) {
            ans[i--]=st.top();
            st.pop();
        }
        
        
        return ans; // Return the result
    }
};
