#include <iostream>
#include "LorentzVector.h"

using namespace std;

int main()
{
	LorentzVector v1, v2(0, 1, 2 ,3), v3;

	cin >> v3;

	cout << v3.norm();
	v3.zboost(-0.5);
	cout << v3 << endl;
	cout << v3.norm() << endl;

	cout << v3 << endl;
	
	v1.t(-1.0/2);
	v1.x(1/2);
	v1.y(1.2e55);
	v1.z(0);

	cout << v1 << endl;

	v1 = v2 + v3;
	v2 = v3 + v2;
	cout << v1 << endl;
	cout << v2 << endl;

	v1 = v2 - v3;
	v2 = v3 - v2;
	cout << v1 << endl;
	cout << v2 << endl;

	v1 = v1 * (-0.33);
	cout << v1 << endl;
	v1 = (-0.33) * v1;
	cout << v1 << endl;

	return 0;
}
