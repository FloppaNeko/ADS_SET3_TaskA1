#include <iostream>
#include <cmath>
#include <random>
#include <ctime>

std::mt19937 mtRand(0xdeadbeef);

const int N = 2000000;


bool inside_circle(double x, double y, double x0, double y0, double r2) {
    return ((x - x0) * (x - x0) + (y - y0) * (y - y0) <= r2);
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double x1, y1, r1;
    std::cin >> x1 >> y1 >> r1;

    double x2, y2, r2;
    std::cin >> x2 >> y2 >> r2;

    double x3, y3, r3;
    std::cin >> x3 >> y3 >> r3;

    double xmin = std::min(std::min(x1 - r1, x2 - r2), x3 - r3) - 1;
    double xmax = std::max(std::max(x1 + r1, x2 + r2), x3 + r3) + 1;
    double ymin = std::min(std::min(y1 - r1, y2 - r2), y3 - r3) - 1;
    double ymax = std::max(std::max(y1 + r1, y2 + r2), y3 + r3) + 1;

    double target_area = (xmax - xmin) * (ymax - ymin);

    std::uniform_real_distribution<double> xrange(xmin, xmax);
    std::uniform_real_distribution<double> yrange(ymin, ymax);

    int corr = 0;

    for (int k = 0; k < N; ++k) {
        double x = xrange(mtRand);
        double y = yrange(mtRand);

        if (inside_circle(x, y, x1, y1, r1*r1) &&
            inside_circle(x, y, x2, y2, r2*r2) &&
            inside_circle(x, y, x3, y3, r3*r3)) {

            ++corr;    
        }
    }

    std::cout << target_area * (double)(corr) / N;
    
    return 0;
}