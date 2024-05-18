#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    double lambda_green = 530; 
    double theta_green = 65.0; 
    double m_green = 3; 
    double lambda_red = 700; 
    double m_red = 2;

    double theta_green_rad = theta_green * PI / 180.0;

    double d = (lambda_green * m_green) / sin(theta_green_rad);

    double theta_red_rad = asin((lambda_red * m_red) / d);
    double theta_red = theta_red_rad * 180.0 / PI;

    printf("The angle for the second-order bright spot for red light is %.2f degrees.\n", theta_red);

    return 0;
}
