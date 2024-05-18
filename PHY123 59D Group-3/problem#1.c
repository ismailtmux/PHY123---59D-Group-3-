#include <stdio.h>

const char* determine_color(int wavelength) {
    if (wavelength >= 380 && wavelength < 450) return "violet";
    else if (wavelength >= 450 && wavelength < 485) return "blue";
    else if (wavelength >= 485 && wavelength < 500) return "cyan";
    else if (wavelength >= 500 && wavelength < 565) return "green";
    else if (wavelength >= 565 && wavelength < 590) return "yellow";
    else if (wavelength >= 590 && wavelength < 625) return "orange";
    else if (wavelength >= 625 && wavelength <= 750) return "red";
    else return "invalid";
}

int main() {
    int lambda;
    int m; 
    float a[3]; 

    printf("Enter the wavelength (in nm): ");
    scanf("%d", &lambda);

    if (lambda < 380 || lambda > 750) {
        printf("Out of the range. Please enter a valid number.\n");
        return 1;
    }

    printf("Enter the order (m): ");
    scanf("%d", &m);

    for (int i = 0; i < 3; i++) {
        printf("Enter slit width a%d (in micrometers): ", i + 1);
        scanf("%f", &a[i]);
    }

    float e[3];
    for (int i = 0; i < 3; i++) {
        e[i] = (lambda * m) / (a[i] * 1000);
        printf("Angle for slit width a%d: %f\n", i + 1, e[i]);
    }

    int max_index = 0;
    for (int i = 1; i < 3; i++) {
        if (e[i] > e[max_index]) {
            max_index = i;
        }
    }

    printf("Slit width a%d bent the light the most.\n", max_index + 1);

    const char* color = determine_color(lambda);
    if (color != "invalid") {
        printf("The color of the light is %s.\n", color);
    }

    return 0;
}
