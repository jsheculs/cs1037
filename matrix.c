#include <math.h>//including standard math library to enable use of sqrt
float norm(float *v,int n) {//function to take pointer to vector v and length of vector and return norm of vector
    float norm_of_vector=0;//declaring and initializing a float type variable called norm_of_vector
    for(int i=0;i<n;i++) {//loop that runs from first element to last element and increments counter i each time
        norm_of_vector+=v[i]*v[i];//computes the multiplication of the vector at each element times itself, then adds each elements square
    }
    return sqrt(norm_of_vector);//square roots the vector and returns it

}
float dot_product(float *v1,float *v2,int n) {//function that recieves the pointers to two vectors v1 and v2 and vector length n. Then the function computes and returns the dot product as a float variable
    float dot_product=0;//declares and initializes a float type vector called dot_product
    for(int i=0;i<n;i++) {//loop runs from first element to last element (n-1th)
        dot_product+=v1[i]*v2[i];//computes the dot product by multiplying vector 1 at element i by vector 2 at element i. For each repetition of the loop the dot product is added to the previous dot product value
    }
    return dot_product;//returns float type dot product
}
void matrix_multiply_vector(float *m, float *v,float *vout, int n) {//function to multiply matrix with pointer *m by vector with pointer *v and output vector *vout with length n
    for(int i=0;i<n;i++)//loop for row 0 to n
        for(int j=0;j<n;j++)//loop for column 0 to n
            vout[i]+=m[i*n+j]*v[j];//output vector at i is matrix element times vector element. Matrix element is the n*ith row plus jth column.

}