#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

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
    ofstream X_1("C:\\Users\\PETA4\\Desktop\\3\\6_sem\\trs\\labs\\trs_1\\out\\X1_out.csv");
    ofstream V_1("C:\\Users\\PETA4\\Desktop\\3\\6_sem\\trs\\labs\\trs_1\\out\\V1_out.csv");

    ofstream Xh_1("C:\\Users\\PETA4\\Desktop\\3\\6_sem\\trs\\labs\\trs_1\\out\\X1_hout.csv");
    ofstream Vh_1("C:\\Users\\PETA4\\Desktop\\3\\6_sem\\trs\\labs\\trs_1\\out\\V1_hout.csv");
    double m = 1.67;
    vector<double> n = { 11, 101, 1001, 10001 };
    for (int j = 0; j < n.size(); j++)
    {
        double x_n_1, x_n = x_n_1 = 0;
        double v_n_1, v_n = v_n_1 = 1;
        double m = 1.67;
        double h = 10. / n[j];
        for (int i = 0; i < n[j]; i++)
        {
            //X_1 << i * h << " " << x_n << endl;
            //V_1 << i * h << " " << v_n << endl;

            x_n = x_n_1 + h * dx_dt(v_n_1);
            v_n = v_n_1 + h * dv_dt(x_n_1, m);
            x_n_1 = x_n;
            v_n_1 = v_n;
            //cout << i * h << ' ' << x_n_1 << endl;
        }
    }
    X_1.close();
    V_1.close();
    //Задание 2

}