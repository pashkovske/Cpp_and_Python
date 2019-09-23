#include <iostream>
#include "LorentzVector.h"

using namespace std;

int main()
{
	LorentzVector v1, v2(0, 1, 2 ,3), v3;

	v3.read();

	cout << v3.norm();
	v3.zboost(-0.5);
	v3.print();
	cout << v3.norm() << endl;

	cout << v1.t() << " " << v2.x() << " " << v3.y() << " " << v3.z() << endl;
	
	v1.t(-1.0/2);
	v1.x(1/2);
	v1.y(1.2e55);
	v1.z(0);

	v1.print();

	v1 = v2.add(v3);
	v2 = v3.add(v2);
	v2.print();
	v1.print();

	v1 = v2.sub(v3);
	v2 = v3.sub(v2);
	v2.print();
	v1.print();

	v1 = v1.mul(-0.33);
	v1.print();

	cout << v2.dot(v3) << endl;
	v2.zboost(0.5);
	v3.zboost(0.5);
	cout << v2.dot(v3) << endl;

	return 0;
}
