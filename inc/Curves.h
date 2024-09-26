#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cmath>
#include <random>
#include <vector>
#if ! _WIN32_
#include <memory>
#include <algorithm>
#endif

#define CURVES_EXPORT __declspec(dllexport)

class Point3D
{
public:
	Point3D(double _x, double _y, double _z) : x{ _x }, y{ _y }, z{ _z } {};
	__declspec(dllexport) void print() {
		std::cout << "x = " << x << " y = " << y << " z = " << z << "\n";
	};
private:
	double x;
	double y;
	double z;
};

class Curves
{
public:
	Curves() {};
	~Curves() {};
	CURVES_EXPORT virtual Point3D getPoint3D(double t) const = 0;
	CURVES_EXPORT virtual Point3D firstDerivative(double t) const = 0;
};

class Circle : public Curves
{
public:
	Circle(double _r) : Curves{}, r { _r }
	{
		if (_r < 0)
		{
			std::cerr << "Radii must be positive\n";
			throw std::exception();
		}
	};
	~Circle() {};
	CURVES_EXPORT Point3D getPoint3D(double t) const override;
	CURVES_EXPORT Point3D firstDerivative(double t) const override;
	CURVES_EXPORT double getRadius() const;
private:
	double r;
	double t;
};

class Ellipse : public Curves
{
public:
	Ellipse(double _a, double _b) : Curves{}, a{ _a }, b{ _b }
	{
		if (_a < 0 || _b < 0)
		{
			std::cerr << "Radii must be positive\n";
			throw std::exception();
		}
	};
	~Ellipse() {};
	CURVES_EXPORT Point3D getPoint3D(double t) const override;
	CURVES_EXPORT Point3D firstDerivative(double t) const override;
private:
	double a;
	double b;
	double t;
};

class Helixes : public Curves
{
public:
	Helixes(double _r, double _step) : Curves{}, r{ _r }, step{ _step }
	{
		if (_r < 0)
		{
			std::cerr << "Radii must be positive\n";
			throw std::exception();
		}
	};
	~Helixes() {};
	CURVES_EXPORT Point3D getPoint3D(double t) const override;
	CURVES_EXPORT Point3D firstDerivative(double t) const override;
private:
	double r;
	double t;
	double step;
};


class Utils
{
public:
	CURVES_EXPORT static std::vector<std::shared_ptr<Curves>> randomCreateCurves(int _size);
	CURVES_EXPORT static void printCurves(std::vector<std::shared_ptr<Curves>> curves, double t);
	CURVES_EXPORT static void printCircle(std::vector<std::shared_ptr<Circle>> curves, double t);
	CURVES_EXPORT static std::vector<std::shared_ptr<Circle>> getOnlyCircle(std::vector<std::shared_ptr<Curves>> curves);
};