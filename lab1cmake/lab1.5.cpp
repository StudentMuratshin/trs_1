#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <vector>

constexpr auto m = 1.67;
constexpr auto E = 1e-3;
using namespace std;

double RHS_x(double v)
{
    return v;
}

double RHS_v(double x, double v)
{
    return cosh(2*x) + v;
}

float bc(float x)
{
    float f = pow(x, 3) + x - 1;
    return f;
}

void secant(float x1, float x2)
{
    float n = 0, xm, x0, c;
    if (bc(x1) * bc(x2) < 0) {
        do {
            x0 = (x1 * bc(x2) - x2 * bc(x1)) / (bc(x2) - bc(x1));

            c = bc(x1) * bc(x0);

            x1 = x2;
            x2 = x0;

            n++;

            if (c == 0)
                break;
            xm = (x1 * bc(x2) - x2 * bc(x1)) / (bc(x2) - bc(x1));
        } while (fabs(xm - x0) >= E); 

    }
}
int main()
{
    ofstream X_5("C:\\Users\\PETA4\\Desktop\\3\\6_sem\\trs\\labs\\trs_1\\out\\X5_out.csv");
    ofstream V_5("C:\\Users\\PETA4\\Desktop\\3\\6_sem\\trs\\labs\\trs_1\\out\\V5_out.csv");
    vector<double> n = { 10001 };
    for (int j = 0; j < n.size(); j++)
    {
        double k11, k12, k13, k14, k21, k22, k23, k24;
        double h = 1. / n[j];
        double x_0, v_0, x_n, v_n;
        double p = -0.5874;
        do 
        {
            p -= 0.0001;
            x_n = x_0 = 0;
            v_n = v_0 = p;

            for (int i = 0; i < n[j]; i++)
            {
                X_5 << i * h << " " << x_n << endl;
                V_5 << i * h << " " << v_n << endl;

                k11 = RHS_x(v_0);
                k21 = RHS_v(x_0, v_0);
                k12 = RHS_x(v_0 + k21 * (h / 2));
                k22 = RHS_v(x_0 + k11 * (h / 2), v_0 + k11 * (h / 2));
                k13 = RHS_x(v_0 + k22 * (h / 2));
                k23 = RHS_v(x_0 + k12 * (h / 2), v_0 + k12 * (h / 2));
                k14 = RHS_x(v_0 + k23 * h);
                k24 = RHS_v(x_0 + k13 * h, v_0 + k13 * h);

                x_n = (x_0 + (h / 6) * (k11 + 2 * k12 + 2 * k13 + k14));
                v_n = (v_0 + (h / 6) * (k21 + 2 * k22 + 2 * k23 + k24));

                x_0 = x_n;
                v_0 = v_n;
            }
            cout << p << endl;
        } while (abs(x_n + v_n) > 0.0001);
        cout << p;
    }
    X_5.close();
    V_5.close();

    //Задание 2

}