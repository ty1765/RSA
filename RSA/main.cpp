/*****************************************
*  Programmer: Tyler Potochnik           *
*  The University Of Akron               *
*                                        *
*  Last Edited: 9/29/2015 3:41 p.m.      *
*                                        *
*****************************************/
#include <iostream>
#include <stdlib.h>
#include <string>
#include "BigInt.cpp"

using namespace std;

int main(int argc, char *argv[]) {

   if (argc==1||argc>5) {
      cout << "Invaild Input!" << endl;
      exit(1);
   }

   if (argc==2) {
      int size = atoi(argv[1]);
      cout << randomPrime(size) << endl;
   }
   if (argc==3) {
   	  BigInt x = 0;
   	  BigInt y = 0;
   	  BigInt gcd;
      BigInt a = string(argv[1]);
      BigInt b = string(argv[2]);
      if(a < b){
      	swap(a, b);
      }
      cout << "a=" << a << ", b=" << b << endl;
      gcd = extendedEuclid(a, b, x, y);
      cout << "GCD = " << gcd << " x = " << x << " y = " << y << endl;
   }
   if (argc==4) {
      BigInt e = string(argv[1]);
      BigInt p = string(argv[2]);
      BigInt q = string(argv[3]);
      BigInt d;
      cout << "e=" << e << ", p=" << p <<", q="<< q << endl;
      d = modInverse(e, p, q);
      cout << "d = " << d << endl;
   }
   if (argc==5) {
      if (argv[1][0]=='e') {
         BigInt e = string(argv[2]);
         BigInt n = string(argv[3]);
         string m = argv[4];
         cout << "e=" << e << ", n=" << n <<", message="<< m << endl;
         encryptRSA(e, n, m);
      }
      else if (argv[1][0]=='d'){
         BigInt d = string(argv[2]);
         BigInt n = string(argv[3]);
         BigInt m = string(argv[4]);
         cout << "d=" << d << ", n=" << n <<", message="<< m << endl;
         decryptRSA(d, n, m);
      }
   }
   return 0;
}

 

