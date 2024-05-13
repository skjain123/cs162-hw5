#include <iostream>

using namespace std;

int ways_to_top(int n) {

	int ways = 0;

	//if remaining steps == 0 then add 1 to the ways.
	if (n == 0) return 1;

	//if theres at least one step left then recursion with 1 less step
	if (n >= 1) ways += ways_to_top(n-1);

	//if theres at least two step left then recursion with 2 less step
	if (n >= 2) ways += ways_to_top(n-2);

	//if theres at least three step left then recursion with 3 less step
	if (n >= 3) ways += ways_to_top(n-3);

	return ways;
}
