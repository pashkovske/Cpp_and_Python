#pragma once
#include <iostream>
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
	
	LorentzVector operator += (const LorentzVector& arg);
	LorentzVector operator -= (const LorentzVector& arg);
	LorentzVector operator *= (double arg);

	LorentzVector operator + (const LorentzVector& right_arg) const;
	LorentzVector operator - (const LorentzVector& right_arg) const;
	friend LorentzVector operator * (const LorentzVector& left_arg, double right_arg);
	friend LorentzVector operator * (double left_arg, const LorentzVector& right_arg);

	void zboost(double beta);
	double dot(const LorentzVector&) const;

	friend std::istream& operator >> (std::istream&, LorentzVector&);
	friend std::ostream& operator << (std::ostream&, const LorentzVector&);
private:
	double t_, x_, y_, z_;
};
