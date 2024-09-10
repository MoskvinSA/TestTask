#define _USE_MATH_DEFINES
#include <iostream>
#include "./Curves.h"


int main()
{
	double t = M_PI / 4;
	std::vector<std::shared_ptr<Curves>> curves;
	std::vector<std::shared_ptr<Circle>> curves_circle;
	std::cout << "All curves : \n";
	curves = Utils::randomCreateCurves(100);
	Utils::printCurves(curves, t);
	
	std::cout << "Circle : \n";
	curves_circle = Utils::getOnlyCircle(curves);
	Utils::printCircle(curves_circle, t);

	std::cout << "Circle sort: \n";
	std::sort(begin(curves_circle), 
			  end(curves_circle), 
			  [](const std::shared_ptr<Circle>& left, const std::shared_ptr<Circle>& right) {
				return left->getRadius() < right->getRadius();
			  });
	Utils::printCircle(curves_circle, t);

	double sum = 0.0;
	for (auto c : curves_circle) {
		sum += (*c).getRadius();
	}
	std::cout << "Sum radiuses: " << sum << "\n";
}
