/*
  2.Towers.cpp
  Print out the steps required to move disks from one spindle to
  another
  -jbs
 */
#include <iostream>
using namespace std;


// towers of hanoi
//   n is the number of disks, start is the spindle that they start
//   on, target is where thery are being moved to, and spare is the
//   "unused" spindle.
void towers(int n, char start, char target, char spare) {
    if (n == 0) return;
    // if (n == 1) {
    // 	cout << "Move disk: " << n << " from " << start << " to " << target << endl;
    // } else {
	towers(n-1, start, spare, target);
	cout << "Move disk: " << n << " from " << start << " to " << target << endl;
	towers(n-1, spare, target, start);
    // }
}


int main() {
    towers(3, 'A', 'C', 'B');
}
