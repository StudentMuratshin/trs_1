#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

constexpr auto m = 1.67;
using namespace std;


double RHS_v(double x)
{
    return -1 / m * (2 * x + 2 * x * tan(x * x) * tan(x * x));
}

double RHS_x(double x)
{
    return x;
}

double xk1(double x)
{
    return RHS_x(x);
}

double xk2(double x, double h)
{
    return RHS_x(x + h / 2. * xk1(x));
}

double xk3(double x, double h)
{
    return RHS_x(x + h / 2. * xk2(x, h));
}

double xk4(double x, double h)
{
    return RHS_x(x + h * xk3(x, h));
}

double vk1(double v)
{
    return RHS_v(v);
}

double vk2(double v, double h)
{
    return RHS_v(v + h / 2. * vk1(v));
}

double vk3(double v, double h)
{
    return RHS_v(v + h / 2. * vk2(v, h));
}

double vk4(double v, double h)
{
    return RHS_v(v + h * vk3(v, h));
}

int main()
{
    ofstream X_3("C:\\Users\\PETA4\\Desktop\\3\\6_sem\\trs\\labs\\trs_1\\out\\X3_out.csv");
    ofstream V_3("C:\\Users\\PETA4\\Desktop\\3\\6_sem\\trs\\labs\\trs_1\\out\\V3_out.csv");
    vector<double> n = { 11, 101, 1001, 10001 };
    for (int j = 0; j < n.size(); j++)
    {
        double h = 10. / n[j];
        double x_0, x_n = x_0 = 0;
        double v_0, v_n = v_0 = 1;

        for (int i = 0; i < n[j]; i++)
        { 
            X_3 << i * h << " " << x_n << endl;
            V_3 << i * h << " " << v_n << endl;
            x_n = x_0 + h / 6. * (xk1(v_0) + 2 * xk2(v_0, h) + 2 * xk3(v_0, h) + xk4(v_0, h));
            v_n = v_0 + h / 6. * (vk1(x_0) + 2 * vk2(x_0, h) + 2 * vk3(x_0, h) + vk4(x_0, h));
            x_0 = x_n;
            v_0 = v_n;
            //cout << i * h << ' ' << x_1 << endl;
        }
    }
    X_3.close();
    V_3.close();

    //Задание 2

}