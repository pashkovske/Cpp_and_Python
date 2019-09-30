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

LorentzVector LorentzVector::operator += (const LorentzVector& arg)
{
	t_ += arg.t();
	x_ += arg.x();
	y_ += arg.y();
	z_ += arg.z();
	return *this;
}


LorentzVector LorentzVector::operator -= (const LorentzVector& arg)
{
	t_ -= arg.t();
	x_ -= arg.x();
	y_ -= arg.y();
	z_ -= arg.z();
	return *this;
}

LorentzVector LorentzVector::operator *= (double arg)
{
	t_ *= arg;
	x_ *= arg;
	y_ *= arg;
	z_ *= arg;
	return *this;
}


LorentzVector LorentzVector::operator + (const LorentzVector& right_arg) const
{
	LorentzVector result = *this;
	result += right_arg;
	return result;
}

LorentzVector LorentzVector::operator - (const LorentzVector& right_arg) const
{
	LorentzVector result = *this;
	result -= right_arg;
	return result;
}

LorentzVector operator * (double left_arg, const LorentzVector& right_arg)
{
	LorentzVector result = right_arg;
	result *= left_arg;
	return result;
}

LorentzVector operator * (const LorentzVector& left_arg, double right_arg)
{
	LorentzVector result = left_arg;
	result *= right_arg;
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

std::istream& operator >> (std::istream& stream, LorentzVector& arg)
{
	stream >> arg.t_ >> arg.x_ >> arg.y_ >> arg.z_;
	return stream;
}

std::ostream& operator << (std::ostream& stream, const LorentzVector& arg)
{
	stream << arg.t_ << " " << arg.x_ << " " << arg.y_ << " " << arg.z_;
	return stream;
}
