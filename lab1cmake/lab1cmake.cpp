#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double dv_dt(double t, double m)
{
    return -1 / m * (2 * t + 2 * t * tan(t * t) * tan(t * t));
}

double dx_dt(double t)
{
    return t;
}


int main()
{
    ofstream X("X_out.csv");
    ofstream V("V_out.csv");
    double x_n_1, x_n = x_n_1 = 0;
    double v_n_1, v_n = v_n_1 = 1;
    double m = 1.67;
    int n = 10001;
    double h = 10. / n;
    for (int i = 0; i < n; i++)
    {
        X << i * h << " " << x_n << endl;
        V << i * h << " " << v_n << endl;
        x_n = x_n_1 + h * dx_dt(v_n_1);
        v_n = v_n_1 + h * dv_dt(x_n_1, m);
        x_n_1 = x_n;
        v_n_1 = v_n;
        cout << i * h << ' ' << x_n_1 << endl;
    }
    X.close();
    V.close();
    //Задание 2

}