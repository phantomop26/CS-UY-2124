/*
  bigUnsigned_begin.cpp
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Put your class and all function definitions here.
class BigUnsigned {
private:
    vector<int> digits;

public:
    friend ostream& operator<<(ostream& os, const BigUnsigned& dig ){
        for (int r = dig.digits.size()-1; r>=0;--r) {
            os << dig.digits[r];
        }
        return os;}
    
    BigUnsigned(int num = 0) {
        if (num == 0) {
            digits.push_back(0);
            return;
        }
        while (num != 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
    }

    BigUnsigned(const string& str) {
        size_t i = 0;
        while (i < str.length() && !isdigit(str[i])) {
            i++;
        }
        if (i == str.length()) {
            digits.push_back(0);
            return;
        }

        while (i < str.length() && str[i] == '0') {
            i++;
        }

        for (; i < str.length(); i++) {
            if (isdigit(str[i])) {
                digits.push_back(str[i] - '0');
            } else {
                break;}}

        if (digits.empty()) {
            digits.push_back(0);}

        int n = digits.size();
        bool swapped;
        for (int j = 0; j < n / 2; j++) {
            swapped = false;
            int temp = digits[j];
            digits[j] = digits[n-j-1];
            digits[n-j-1] = temp; 
            }
        }
    BigUnsigned& operator+=(const BigUnsigned& other) {
        int carry = 0;
        size_t maxLength = max(digits.size(), other.digits.size());

        for (size_t i = 0; i < maxLength || carry; ++i) {
            if (i == digits.size())
                digits.push_back(0);

            digits[i] += carry + (i < other.digits.size() ? other.digits[i] : 0);
            carry = digits[i] >= 10;
            if (carry)
                digits[i] -= 10;
        }
        return *this;
    }
    BigUnsigned& operator++() {
        int carry = 1;
        for (size_t i = 0; i < digits.size(); ++i) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if (carry > 0) {
            digits.push_back(carry);
        }
        return *this;
    }
    BigUnsigned operator++(int) {
        BigUnsigned temp(*this);
        ++(*this);
        return temp;
    }
    operator  bool() const {
        return !(digits.empty() || (digits[0]==0 && digits.size()==1));
    }
    friend BigUnsigned operator+(const BigUnsigned& num1, const BigUnsigned& num2);
    friend bool operator==(const BigUnsigned& lhs, const BigUnsigned& rhs);
    friend bool operator!=(const BigUnsigned& lhs, const BigUnsigned& rhs);
    friend bool operator<(const BigUnsigned& lhs, const BigUnsigned& rhs);
    friend bool operator<=(const BigUnsigned& lhs, const BigUnsigned& rhs);
    friend bool operator>(const BigUnsigned& lhs, const BigUnsigned& rhs);
    friend bool operator>=(const BigUnsigned& lhs, const BigUnsigned& rhs);
};

int main() {
    BigUnsigned zero;
    BigUnsigned one(1);

    cout << "zero: " << zero << endl;
    cout << "one: " << one << endl;

    BigUnsigned val = 1;
    cout << "val: " << val << endl;
    cout << "++val: " << ++val << endl;
    cout << "val: " << val << endl;
    cout << "val++: " << val++ << endl;
    cout << "val: " << val << endl;
    
    cout << "(one + zero): " << (one + zero) << endl;
    cout << "(one + one): " <<  (one + one) << endl;

    cout << boolalpha;
    cout << "one < one: " << (one < one) << endl;
    cout << "zero < one: " << (zero < one) << endl;

    BigUnsigned a = 123;
    BigUnsigned b = 1234;
    BigUnsigned c = 124;
    BigUnsigned d = 12345;

    cout << "a: " << a << ", b: " << b 
         << ", c: " << c << ", d: " << d << endl;
    cout << "a + d: " << (a + d) << endl;
    cout << "d + d: " << (d + d) << endl;
    cout << "a < d: " << (a < d) << endl;
    cout << "d < a: " << (d < a) << endl;
    cout << "zero == zero: " << (zero == zero) << endl
         << "zero == one: " << (zero == one) << endl
         << "a == a: " << (a == a) << endl
         << "a == d: " << (a == d) << endl
         << "d == a: " << (d == a) << endl;

    // cout << "(zero == 0): " << (zero == 0) << endl
    //      << "(one == 0): " << (one == 0) << endl
    //      << "(1 == one): " << (1 == one) << endl;

    // +=
    cout << "b: " << b << ", c: " << c << endl;
    cout << "(c += b): " << (c += b) << endl;
    cout << "b: " << b << ", c: " << c << endl;


    BigUnsigned x = a;
    cout << "x: " << x << ", a: " << a << endl
         << "x == a: " << (x == a) << endl
         << "a == x: " << (a == x) << endl
         << "a < x: " << (a < x) << endl
         << "a > x: " << (a > x) << endl;
    
    cout << "x > a: " << (x > a) << endl
         << "x >= a: " << (x >= a) << endl
         << "x <= a: " << (x <= a) << endl
         << "x != a: " << (x != a) << endl;
         
    
    BigUnsigned big("987654321");
    BigUnsigned big2("  ");
    BigUnsigned big3("felix");
    BigUnsigned big4("00987654321");

    cout << "big: " << big << endl
         << "big2: " << big2 << endl
         << "big3: " << big3 << endl
         << "big4: " << big4 << endl;

    BigUnsigned big5(98765);
    BigUnsigned big6(2457);
    cout << "big5: " << big5  << ", big6: " <<  big6 << endl;
    cout << "(big5 + big6): " << (big5 + big6) << endl;
    cout << "(big6 + big5): " << (big6 + big5) << endl;


    cout << zero << " is " << (zero ? "true" : "false") << endl;
    cout << one << " is " << (one ? "true" : "false") << endl;
    cout << big4 << " is " << (big4 ? "true" : "false") << endl;
}


BigUnsigned operator+(const BigUnsigned& num1, const BigUnsigned& num2) {
    BigUnsigned result(num1);
    result+=num2;
    return result;
}
bool operator==(const BigUnsigned& lhs, const BigUnsigned& rhs) {
    return lhs.digits == rhs.digits;
    }
bool operator!=(const BigUnsigned& lhs, const BigUnsigned& rhs) {
    return !(lhs == rhs);
    }
bool operator<(const BigUnsigned& lhs, const BigUnsigned& rhs) {
    if (lhs.digits.size() != rhs.digits.size())
        return lhs.digits.size() < rhs.digits.size();
        
    for (int i = lhs.digits.size() - 1; i >= 0; --i) {
        if (lhs.digits[i] != rhs.digits[i])
            return lhs.digits[i] < rhs.digits[i];
        }
        return false; 
    }
bool operator<=(const BigUnsigned& lhs, const BigUnsigned& rhs) {
    return !(rhs < lhs);
    }

bool operator>(const BigUnsigned& lhs, const BigUnsigned& rhs) {
    return rhs < lhs;
    }

bool operator>=(const BigUnsigned& lhs, const BigUnsigned& rhs) {
    return !(lhs < rhs);
    }