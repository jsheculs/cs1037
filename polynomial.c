
float horner(float *p, int n, float x){//the function horner with parameters p pointing to an array, n coefficients, and x
  float polynomialValue = p[0];//declaring and initializing a float variable polynomialValue with the value equal to the first coefficient of the polynomial
  for(int i = 1; i < n; i++){//for loop that runs from the second element until one less than the nth element
    polynomialValue = polynomialValue*x + p[i];//value of the polynomial is the initial polynomial value multiplied by x, plus the polynomial at element i
    }
    return polynomialValue;//returns polynomial outside the for loop
}
void derivative(float *p, float *d, int n){//function to compute the derivative of the polynomial with parameters p pointing to array, d pointing to coefficient array, and n coefficients
  for(int i = 0; i < (n-1); i++){//loop that runs from the first element to n-2nd element
    d[i] = p[i]*(n-1-i);//derivative coefficient value at element i is the polynomial at i times the coefficient number minus one
}
}



