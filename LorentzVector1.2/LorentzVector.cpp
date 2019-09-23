#include "LorentzVector.h"
#include <cmath>
#include <iostream>

LorentzVector::LorentzVector() {
	t_ = 0;
	x_ = 0;
	y_ = 0;
	z_ = 0;
}

LorentzVector::LorentzVector(double t, double x)
{
	t_ = t;
	x_ = x;
	y_ = 0;
	z_ = 0;
}

LorentzVector::LorentzVector(double t, double x, double y)
{
	t_ = t;
	x_ = x;
	y_ = y;
	z_ = 0;
}

LorentzVector::LorentzVector(double t, double x, double y, double z)
{
	t_ = t;
	x_ = x;
	y_ = y;
	z_ = z;
}

double LorentzVector::t() const {return t_;}
double LorentzVector::x() const {return x_;}
double LorentzVector::y() const {return y_;}
double LorentzVector::z() const {return z_;}

double LorentzVector::norm() const
{
	return C*C*t_*t_ - x_*x_ - y_*y_ - z_*z_;
}

void LorentzVector::t(double arg) {t_ = arg;}
void LorentzVector::x(double arg) {x_ = arg;}
void LorentzVector::y(double arg) {y_ = arg;}
void LorentzVector::z(double arg) {z_ = arg;}

LorentzVector LorentzVector::add(const LorentzVector& right_arg) const
{
	LorentzVector result(t_ + right_arg.t(), x_ + right_arg.x(), y_ + right_arg.y(), z_ + right_arg.z());
	return result;
}

LorentzVector LorentzVector::sub(const LorentzVector& right_arg) const
{
	LorentzVector result(t_ - right_arg.t(), x_ - right_arg.x(), y_ - right_arg.y(), z_ - right_arg.z());
	return result;
}

LorentzVector LorentzVector::mul(double arg) const
{
	LorentzVector result(t_*arg, x_*arg, y_*arg, z_*arg);
	return result;
}

void LorentzVector::zboost(double beta)
{
	if (beta > -1 && beta < 1)
	{
		double gamma = 1.0/sqrt(1 - beta*beta);
		double z1 = gamma*(z_ - beta*C*t_);
		double t1 = gamma*(t_ - beta/C*z_);
		z_ = z1;
		t_ = t1;
	}
}

double LorentzVector::dot(const LorentzVector& right_arg) const
{
	return C*t_ * C*right_arg.t() - x_ * right_arg.x() - y_ * right_arg.y() - z_ * right_arg.z();
}

void LorentzVector::read()
{
	double t, x, y, z;
	std::cin >> t >> x >> y >> z;
	t_ = t;
	x_ = x;
	y_ = y;
	z_ = z;
}

void LorentzVector::print() const
{
	std::cout << '(' << t_ << ", " << x_ << ", " << y_ << ", " << z_ << ')' << std::endl;
}
