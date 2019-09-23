#ifndef LORENTZ_VECTOR
#define LORENTZ_VECTOR
#define C 1

class LorentzVector
{
public:
	LorentzVector();
	LorentzVector(double t, double x);
	LorentzVector(double t, double x, double y);
	LorentzVector(double t, double x, double y, double z);

	double t() const;
	double x() const;
	double y() const;
	double z() const;
	double norm() const;

	void t(double arg);
	void x(double arg);
	void y(double arg);
	void z(double arg);
	
	void operator += (const LorentzVector& arg);
	void operator -= (const LorentzVector& arg);
	void operator *= (double arg);

	LorentzVector operator + (const LorentzVector& right_arg) const;
	LorentzVector operator - (const LorentzVector& right_arg) const;
	LorentzVector operator - (const LorentzVector& right_arg) const;

	void zboost(double beta);
	double dot(const LorentzVector&) const;

	void read();
	void print() const;
private:
	double t_, x_, y_, z_;
};
#endif
