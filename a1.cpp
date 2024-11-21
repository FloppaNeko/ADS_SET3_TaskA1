#include <iostream>
#include <cmath>
#include <random>
#include <ctime>
#include <fstream>

std::mt19937 mtRand(0xdead);
std::uniform_real_distribution<double> range1(0.5, 2.5);
std::uniform_real_distribution<double> range2(0.0, 3.0);

const double TRUE_S = 0.9445171858994637;
const double TARGET_S1 = 4.0;
const double TARGET_S2 = 9.0;


bool inside_circle(double x, double y, double x0, double y0, double r2) {
    return ((x - x0) * (x - x0) + (y - y0) * (y - y0) <= r2);
}

bool check_point(double x, double y) {
    return (
        inside_circle(x, y, 1.0, 1.0, 1.0) &&
        inside_circle(x, y, 1.5, 2.0, 1.25) &&
        inside_circle(x, y, 2.0, 1.5, 1.25)
    );
}

int main() {
    std::fstream fout("data.csv", std::ios::out);

    for (int n = 100; n <= 100000; n += 500) {
        int corr1 = 0;
        int corr2 = 0;

        for (int k = 0; k < n; ++k) {
            double x1 = range1(mtRand);
            double y1 = range1(mtRand);

            double x2 = range2(mtRand);
            double y2 = range2(mtRand);

            //std::cout << x << ' ' << y << '\n';

            if (check_point(x1, y1)) {
                ++corr1;
            }
            if (check_point(x2, y2)) {
                ++corr2;
            }
        } 

        //std::cout << corr << '\n';

        double s1 = TARGET_S1 * corr1 / n;
        double s2 = TARGET_S2 * corr2 / n;

        double rel_err1 = std::abs(s1 - TRUE_S) / TRUE_S;
        double rel_err2 = std::abs(s2 - TRUE_S) / TRUE_S;

        fout << n << ',' << s1 << ',' << rel_err1 << ',' <<
            s2 << ',' <<  rel_err2 << '\n';
    }

    return 0;
}