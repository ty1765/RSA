/*##############################
  # written by a UA student.   #
  # all rights are reserved.   # 
  ##############################*/
  
#ifndef BIGINT_H
#define	BIGINT_H

#include <algorithm>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <time.h>

using namespace std;

typedef unsigned char uchar;
typedef list<uchar> IntList;

class BigInt {
private:
   IntList intAsList;
   bool isPositive;
public:
   BigInt();
   BigInt(string const&);
   BigInt(IntList const&, bool isPositive);
   BigInt(int);
   
   int getLength() const;
   //bool isPrime();
   
   //static BigInt random(int const& digits);
   //static BigInt randomOdd(int const& digits);

   static BigInt randomPrime(int const& digits);
   BigInt extendedEuclid(int a, int b, int &x, int &y);
   BigInt modInverse(BigInt e, BigInt p, BigInt q);
   string encryptRSA(BigInt e, BigInt n, string m);
   string decryptRSA(BigInt d, BigInt n, string c);

   static BigInt modExp(BigInt const& base, BigInt exponent, BigInt const& mod);
   
   friend ostream& operator<<(ostream& stream, BigInt const& num);
   friend ostream& operator<<(ostream& stream, int const& num);
   
   bool operator<(BigInt const& thatNum) const;
   bool operator<(int const& thatNum) const;
   bool operator>(BigInt const& thatNum) const;
   bool operator>(int const& thatNum) const;
   bool operator<=(BigInt const& thatNum) const;
   bool operator<=(int const& thatNum) const;
   bool operator>=(BigInt const& thatNum) const;
   bool operator>=(int const& thatNum) const;
   bool operator==(BigInt const& thatNum) const;
   bool operator==(int const& thatNum) const;
   bool operator!=(BigInt const& thatNum) const;
   bool operator!=(int const& thatNum) const;
   BigInt operator+(BigInt const& thatNum) const;
   BigInt operator+(int const& thatNum) const;
   BigInt operator-(BigInt const& thatNum) const;
   BigInt operator-(int const& thatNum) const;
   BigInt operator-() const;
   BigInt operator%(BigInt const& mod) const;
   BigInt operator%(int const& mod) const;
   BigInt operator*(BigInt const& thatNum) const;
   BigInt operator*(int const& thatNum) const;
   BigInt operator/(BigInt const& thatNum) const;
   BigInt operator/(int const& thatNum) const;
   BigInt half();
   
private:
   void borrow(IntList::reverse_iterator place) const;
   //bool fermatTest(int);  
};

#endif
