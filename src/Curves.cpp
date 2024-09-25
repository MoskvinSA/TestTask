#include "./Curves.h"

Point3D Circle::getPoint3D(double t) const
{
	Point3D point(r * std::cos(t), r * std::sin(t), 0);
	return point;
}

Point3D Circle::firstDerivative(double t) const
{
	Point3D point(-r * std::sin(t), r * std::cos(t), 0);
	return point;
}

double Circle::getRadius() const
{
	return r;
}

Point3D Ellipse::getPoint3D(double t) const
{
	Point3D point(a * std::cos(t), b * std::sin(t), 0);
	return point;
}

Point3D Ellipse::firstDerivative(double t) const
{
	Point3D point(-a * std::sin(t), b * std::cos(t), 0);
	return point;
}

Point3D Helixes::getPoint3D(double t) const
{
	Point3D point(r * std::cos(t), r * std::sin(t), step * t / (2 * M_PI));
	return point;
}

Point3D Helixes::firstDerivative(double t) const
{
	Point3D point(-r * std::sin(t), r * std::cos(t), step / (2 * M_PI));
	return point;
}

std::vector<std::shared_ptr<Curves>> Utils::randomCreateCurves(int _size)
{
	std::vector<std::shared_ptr<Curves>> curves;
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 2);
	std::uniform_real_distribution<> radius(1.0, 100.0);
	std::uniform_real_distribution<> step(1.0, 10.0);

	for (int i = 0; i < _size; i++) {
		switch (dist(rng))
		{
		case 0:
			curves.push_back(std::make_shared<Circle>(radius(rng)));
			break;
		case 1:
			curves.push_back(std::make_shared<Ellipse>(radius(rng), radius(rng)));
			break;
		case 2:
			curves.push_back(std::make_shared<Helixes>(radius(rng), step(rng)));
			break;
		default:
			break;
		}
	}
	return curves;
}

void Utils::printCurves(std::vector<std::shared_ptr<Curves>> curves, double t)
{
	for (auto c : curves) {
		std::cout << "Point: ";
		Point3D point = (*c).getPoint3D(t);
		point.print();
		std::cout << "Derivative: ";
		Point3D point_derivative = (*c).firstDerivative(t);
		point_derivative.print();
	}
}

void Utils::printCircle(std::vector<std::shared_ptr<Circle>> curves, double t)
{
	for (auto c : curves) {
		std::cout << "Point: ";
		Point3D point = (*c).getPoint3D(t);
		point.print();
		std::cout << "Derivative: ";
		Point3D point_derivative = (*c).firstDerivative(t);
		point_derivative.print();
	}
}


std::vector<std::shared_ptr<Circle>> Utils::getOnlyCircle(std::vector<std::shared_ptr<Curves>> curves)
{
	std::vector<std::shared_ptr<Circle>> curves_circle;
	for (auto c : curves) {
		std::shared_ptr<Circle> circle = std::dynamic_pointer_cast<Circle>(c);
		if (circle)
			curves_circle.push_back(circle);
	}
	return curves_circle;
}