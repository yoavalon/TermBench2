#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Coordinate;

void rotate(Coordinate *coord, double angle_x, double angle_y, double angle_z) {
    double rad_x = angle_x * M_PI / 180.0;
    double rad_y = angle_y * M_PI / 180.0;
    double rad_z = angle_z * M_PI / 180.0;
    double cos_x = cos(rad_x), sin_x = sin(rad_x);
    double cos_y = cos(rad_y), sin_y = sin(rad_y);
    double cos_z = cos(rad_z), sin_z = sin(rad_z);
    double temp_x = coord->x, temp_y = coord->y, temp_z = coord->z;
    coord->x = temp_x;
    coord->y = temp_y * cos_x - temp_z * sin_x;
    coord->z = temp_y * sin_x + temp_z * cos_x;
    temp_x = coord->x, temp_y = coord->y, temp_z = coord->z;
    coord->x = temp_x * cos_y + temp_z * sin_y;
    coord->y = temp_y;
    coord->z = -temp_x * sin_y + temp_z * cos_y;
    temp_x = coord->x, temp_y = coord->y, temp_z = coord->z;
    coord->x = temp_x * cos_z - temp_y * sin_z;
    coord->y = temp_x * sin_z + temp_y * cos_z;
    coord->z = temp_z;
}

double distance(Coordinate p1, Coordinate p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double dz = p1.z - p2.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() {
    Coordinate p1 = {1.0, 2.0, 3.0};
    Coordinate p2 = {4.0, 5.0, 6.0};
    printf("Initial distance: %f\n", distance(p1, p2));
    double angle_x = 30, angle_y = 45, angle_z = 60;
    rotate(&p1, angle_x, angle_y, angle_z);
    rotate(&p2, angle_x, angle_y, angle_z);
    printf("Rotated distance: %f\n", distance(p1, p2));
    while (1) {
        angle_x += 1;
        angle_y += 2;
        angle_z += 3;
        rotate(&p1, angle_x, angle_y, angle_z);
        rotate(&p2, angle_x, angle_y, angle_z);
        printf("New distance: %f\n", distance(p1, p2));
    }
    return 0;
}