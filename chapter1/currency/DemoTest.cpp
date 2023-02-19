#include<iostream>
#include"currency.h"

int main()
{
    // currency g, h(3, 50), i, j;
    // g.setValue(2,25);
    // i.setValue(-6.45);
    // j = h + g;
    // cout << h << " + " << g << " = "<< j << endl;
    // j = i + g + h;
    // cout<< i << " + " << g << " + "<< h << " = " << j << endl;
    // cout << "Increase " << i << " by " << g << " and then add "<< h<<endl;
    // j = (i += g) + h;
    // cout << "Result is " << j << endl;
    // cout << "Incremented object is " << i << endl;
    currency g(5,60),k(3,20);
    cout<< "before : " << g << endl;
    g.subtract(k);
    cout<< "after : " << g << endl;
    return 0;
}   
