#include <iostream> 
#include <iomanip>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	double a,b,c,s;
	
	cin >> a >> b >> c;
	
	double p = a + b +c;
	p /= 2;
	s = sqrt(p * (p-a) * (p-b) * (p-c));
	
	printf("%.1f\n", s);
	
	return 0;
}
