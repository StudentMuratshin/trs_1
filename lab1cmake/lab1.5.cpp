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

double rk4(double p)
{
    vector<double> n = { 10001 };
    double k0, k1, k2, k3;
    double h = 1. / n[0];
    double x_0, v_0, u_n, v_n, u_0;
    for (int j = 0; j < n.size(); j++)
    {
        x_0 = 0;
        u_n = u_0 = 0;
        v_n = v_0 = p;

        k0 = v_0 + h * (RHS_v(x_0, v_0));

        for (int i = 0; i < n[j]; i++)
        {
            x_0 = i * h;
            u_0 = u_n;
            v_0 = k0;

            k0 = v_0 + h * (RHS_v(x_0, v_0));
            k1 = v_0 + h * (RHS_v(x_0 + h / 2., v_0 + h * k0 / 2.));
            k2 = v_0 + h * (RHS_v(x_0 + h / 2., v_0 + h * k1 / 2.));
            k3 = v_0 + h * (RHS_v(x_0 + h, v_0 + h * k2));

            u_n = (u_0 + (h / 6) * (k0 + 2 * k1 + 2 * k2 + k3));
            v_n = k0;
        }
    }
    return (u_n + v_n);
}

double find_p()
{
    double p1 = 0;
    double p2 = -1.;
    double p = (p2 - p1) / 2.;
    while (rk4(p1) > 1e-10)
    {
        p = (p2 + p1) / 2.;
        if (rk4(p1) * rk4(p) < 0)
        {
            p2 = p;
        }
        else if (rk4(p) * rk4(p2) < 0)
        {
            p1 = p;
        }
    }
    return p1;
}

int main()
{
    ofstream X_5("C:\\Users\\PETA4\\Desktop\\trs\\trs_1\\out\\X5_out.csv");
    ofstream V_5("C:\\Users\\PETA4\\Desktop\\trs\\trs_1\\out\\V5_out.csv");
    vector<double> n = { 10001 };
    double p = find_p();
    for (int j = 0; j < n.size(); j++)
    {
        double k0, k1, k2, k3;
        double h = 1. / n[j];
        double x_0, v_0, u_n, v_n, u_0;
        x_0 = 0;
        u_n = u_0 = 0;
        v_n = v_0 = p;

        k0 = v_0 + h * (RHS_v(x_0, v_0));

        for (int i = 0; i < n[j]; i++)
        {
            X_5 << i * h << " " << u_n << endl;
            V_5 << i * h << " " << v_n << endl;

            x_0 = i * h;
            u_0 = u_n;
            v_0 = k0;

            k0 = v_0 + h * (RHS_v(x_0, v_0));
            k1 = v_0 + h * (RHS_v(x_0 + h / 2., v_0 + h * k0 / 2.));
            k2 = v_0 + h * (RHS_v(x_0 + h / 2., v_0 + h * k1 / 2.));
            k3 = v_0 + h * (RHS_v(x_0 + h, v_0 + h * k2));

            u_n = (u_0 + (h / 6) * (k0 + 2 * k1 + 2 * k2 + k3));
            v_n = k0;

        }
    }
    X_5.close();
    V_5.close();

    //Задание 2

}