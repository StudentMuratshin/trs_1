#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


double RHS_v(double t, double m)
{
    return -1 / m * (2 * t + 2 * t * tan(t * t) * tan(t * t));
}

double RHS_x(double t)
{
    return t;
}


int main()
{
    ofstream X_2("X2_out.csv");
    ofstream V_2("V2_out.csv");
    double x_2, x_n = x_2 = 0;
    double v_2, v_n = v_2 = 1;
    double m = 1.67;
    vector<int> n = { 10001, 1001, 101, 11 };
    for (int j = 0; j < n.size(); j++)
    {
        double h = 10. / n[j];
        double x_1 = x_2 + h * RHS_x(v_2);
        double v_1 = v_2 + h * RHS_v(x_2, m);
        for (int i = 0; i < n[j]; i++)
        {
            X_2 << i * h << " " << x_n << endl;
            V_2 << i * h << " " << v_n << endl;
            x_n = x_1 + h / 2. * (3 * RHS_x(v_1) - RHS_x(v_2));
            v_n = v_1 + h / 2. * (3 * RHS_v(x_1, m) - RHS_v(x_2, m));
            x_2 = x_1;
            v_2 = v_1;
            x_1 = x_n;
            v_1 = v_n;
            //cout << i * h << ' ' << x_1 << endl;
        }
    }
    X_2.close();
    V_2.close();
        
    //Задание 2

}