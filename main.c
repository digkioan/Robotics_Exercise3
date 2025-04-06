#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_LINE_LENGTH 1024

double degrees_to_radians(double degrees) {
    return degrees * PI / 180.0;
}

int main() {
    char line[MAX_LINE_LENGTH];
    double x = 0.0, y = 0.0, theta = 0.0;

    fgets(line, sizeof(line), stdin);

    int N;
    char *ptr = line;
    sscanf(ptr, "%d", &N);

    while (*ptr != '\0' && *ptr != ' ') ptr++; // Βρες το πρώτο κενό
    while (*ptr == ' ') ptr++; // Πήγαινε στο επόμενο νούμερο

    for (int i = 0; i < N; i++) {
        double theta_i, v_i, t_i;
        sscanf(ptr, "%lf %lf %lf", &theta_i, &v_i, &t_i);

        theta += theta_i;
        double distance = v_i * t_i;
        double theta_rad = degrees_to_radians(theta);
        x += distance * cos(theta_rad);
        y += distance * sin(theta_rad);

        printf("%.1f %.1f %.1f\n", x, y, theta);

        while (*ptr != '\0' && *ptr != ' ') ptr++;
        while (*ptr == ' ') ptr++;
        while (*ptr != '\0' && *ptr != ' ') ptr++;
        while (*ptr == ' ') ptr++;
        while (*ptr != '\0' && *ptr != ' ') ptr++;
        while (*ptr == ' ') ptr++;
    }

    return 0;
}