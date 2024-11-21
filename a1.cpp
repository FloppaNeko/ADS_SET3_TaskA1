#include <iostream>
#include <cmath>
#include <random>
#include <ctime>
#include <fstream>

std::mt19937 mtRand(0xdeadbeef);
std::uniform_real_distribution<double> range(0.5, 2.5);

const double TRUE_S = 0.9445171858994637;
const double TARGET_S = 4.0;


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
        int corr = 0;

        for (int k = 0; k < n; ++k) {
            double x = range(mtRand);
            double y = range(mtRand);

            //std::cout << x << ' ' << y << '\n';

            if (check_point(x, y)) {
                ++corr;
            }
        } 

        //std::cout << corr << '\n';

        double s = TARGET_S * corr / n;
        double rel_err = std::abs(s - TRUE_S) / TRUE_S;

        fout << n << ',' << s << ',' << rel_err << '\n';
    }

    return 0;
}