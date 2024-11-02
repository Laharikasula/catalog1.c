#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to decode a value from a given base
long long decode_value(int base, const char *value) {
    return strtoll(value, NULL, base);
}

// Lagrange interpolation function to find the constant term c
double lagrange_interpolation(int *x_values, long long *y_values, int k) {
    double result = 0.0;

    for (int i = 0; i < k; i++) {
        double term = y_values[i];
        for (int j = 0; j < k; j++) {
            if (i != j) {
                term *= (0 - x_values[j]) / (double)(x_values[i] - x_values[j]);
            }
        }
        result += term;
    }
    return result;
}

// Solve the test case with given values and print the result
void solve_test_case(int n, int k, int *x_values, char **y_values_str, int *bases, int expected_output) {
    long long y_values[k];
    
    // Decode the y values based on their respective bases
    for (int i = 0; i < k; i++) {
        y_values[i] = decode_value(bases[i], y_values_str[i]);
    }

    // Calculate the constant term (c) using Lagrange interpolation
    long long secret = (long long)round(lagrange_interpolation(x_values, y_values, k));
    
    // Print the expected and actual results
    printf("Expected constant term (c): %d, Calculated constant term (c): %lld\n", expected_output, secret);
}

int main() {
    int n1 = 4;
    int k1 = 3;
    int x_values1[] = {1, 2, 3};
    char *y_values_str1[] = {"4", "111", "12"};
    int bases1[] = {10, 2, 10};
    int expected_output1 = 1;

    printf("Test Case 1:\n");
    solve_test_case(n1, k1, x_values1, y_values_str1, bases1, expected_output1);

    // Test Case 2: Expected output is 7
    int n2 = 10;
    int k2 = 7;
    int x_values2[] = {1, 2, 3, 4, 5, 6, 7};
    char *y_values_str2[] = {
        "13444211440455345511", "aed7015a346d63", "6aeeb69631c227c", 
        "elb5e05623d881f", "316034514573652620673", "2122212201122002221120200210011020220200", 
        "20120221122211000100210021102001201112121"
    };
    int bases2[] = {6, 15, 15, 16, 8, 3, 3};
    int expected_output2 = 7;

    printf("\nTest Case 2:\n");
    solve_test_case(n2, k2, x_values2, y_values_str2, bases2, expected_output2);

    return 0;
}



output :


Test Case 1:
Expected constant term (c): 1, Calculated constant term (c): 3

Test Case 2:
Expected constant term (c): 7, Calculated constant term (c): -9223372036854775808