#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float train[][2] = {
    {0,0},
    {1,1},
    {2,4},
    {3,9},
    {4,16},
    {5,25},
    {6,36},
    {7,49},
    {8,64},
    {9,81},
    {10,100},
};

#define train_count (sizeof(train)/sizeof(train[0]))

float rand_float(void)
{    
    return (float) rand()/ (float) RAND_MAX;
}

float costf(float w, float b){

    float result = 0.0f;
    for (size_t i=0 ;i < train_count; ++i){
    
       float x = train[i][0];
       float y = x*w + b;
       float d = y - train[i][1];
       result +=d*d;
       
    };
    result /= train_count;

 
    return result;
};

int main(void) {
    
    srand(3);
    float eps= 1e-4;
    float rate = 1e-3;
    float w = rand_float()*10.0f;
    float b = rand_float()*10.0f;
    for (size_t i = 0; i < 1000; ++i){
        float dw = (costf(w + eps,b) - costf(w,b))/eps;
        float db = (costf(w, b + eps) - costf(w,b))/eps;
        w -= dw*rate;
        b -= db*rate;
    };

    for (size_t i=0 ; i< train_count; ++i){
        float x = train[i][0];
        float y = x*w + b;
        float deltaf = (train[i][1]-y)/(train[i][1]) ;
        printf("Learned value: %f, expected value: %f,discrepancy:%f\n", y,train[i][1], deltaf);
    };

return 0;

}
