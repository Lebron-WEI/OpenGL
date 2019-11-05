#include <gl/glut.h>
#include <cstdlib>
#include <iostream>
#include <utility>
using namespace std;

int main()
{
	int n = 0;
	int result = 1;
	for (int i = 1; i <= n; result *= i, i++);
	cout<<result<<endl;
}