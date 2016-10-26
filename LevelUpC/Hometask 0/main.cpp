//
//  main.cpp
//  test
//
//  Created by Максим Шилов on 24.10.16.
//  Copyright © 2016 Максим Шилов. All rights reserved.
//

#include <iostream>
using namespace std;

void transform10To2 (double a){
    int temp = a, countAr = 1;
    while(temp>=2){
        temp/=2;
        countAr++;
    }
    char ch[countAr];
    int count = 0;
    do{
        ch[count] = int(a) % 2 + 48;
        count++;
        a /= 2;
    }
    while(a >= 2);
    ch[count] = int(a) % 2 + 48;

    for (int i = count; i >= 0; i--){
        cout << ch[i];
    }
}

int main(int argc, const char * argv[]) {
    double a;
    cout << "Enter number: ";
    cin >> a;
    cout << "Binary number is: ";
    transform10To2(a);
    cout << endl;
    return 0;
}
