/*
  The STL. Standard Template Library
  Sec B - 24S
*/

#include <vector>
#include <iostream> 
#include <list>
#include <algorithm>
using namespace std;

char* myFind(char* start, char* stop, char target) {
    for (char* p = start; p != stop; ++p) {
        if (*p == target) return p;
    }
    return stop;
}

template <typename T, typename U>
T myFind(T start, T stop, const U& target) {
    for (T p = start; p != stop; ++p) {
        if (*p == target) return p;
    }
    return stop;
}

template <typename T, typename Pred>
T myFind_if(T start, T stop, const Pred& myPred) {
    for (T p = start; p != stop; ++p) {
        if (myPred(*p)) return p;
    }
    return stop;
}

bool isEven(int val) { return val % 2 == 0; }

class IsEvenFunctor {
public:
    // Function call operator
    bool operator() (int val) const { return val % 2 == 0; }
};

class IsMultiple {
public:
    IsMultiple(int divisor) : divisor(divisor) {}
    // Function call operator
    bool operator() (int val) const { return val % divisor == 0; }
private:
    int divisor;
};

int main() {

  char arr[] = "Bjarne Stroustrup";
  int len = 17;
  sort(arr, arr+len);

  list<char> lc(arr, arr+len);

  vector<char> vc(lc.begin(), lc.end());

  list<char>::iterator where = find(lc.begin(), lc.end(), 'S');

  where = find(lc.begin(), lc.end(), 'Q');

  char* where2 = myFind(arr, arr+len, 'j');

  vector<int> vi { 2, 6, 7, 11, 8, 13 };

  vector<int>::iterator where3 = myFind_if(vi.begin(), vi.end(), isEven);

  // lambda expression / function
  where3 = myFind_if(vi.begin(), vi.end(), [] (int val) { return val % 2 == 0; } );
    cout<<*where3<<endl;
  [] { cout << "I'm a lambda\n"; } ();
  
  IsEvenFunctor isEvenFunctorInstance;

  if (isEvenFunctorInstance(28)) {
      cout << "28 is even\n";
  } else {
      cout << "28 is not even\n";
  }

  where3 = myFind_if(vi.begin(), vi.end(), isEvenFunctorInstance);

  where3 = myFind_if(vi.begin(), vi.end(), IsEvenFunctor());

  where3 = myFind_if(vi.begin(), vi.end(), IsMultiple(3));
  auto myLambda =   [] { cout << "I'm a lambda\n"; };
  //auto x = 17;
  auto x = 17.0;
}

