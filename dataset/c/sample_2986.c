#include <math.h>

void rotate_point(double x, double y, double z, double angle_x, double angle_y, double angle_z, double *x_new, double *y_new, double *z_new) {
    double rad_x = angle_x * M_PI / 180.0;
    double rad_y = angle_y * M_PI / 180.0;
    double rad_z = angle_z * M_PI / 180.0;
    double x_rot = x * cos(rad_y) * cos(rad_z) - y * sin(rad_z) + z * sin(rad_y) * cos(rad_z);
    double y_rot = x * cos(rad_y) * sin(rad_z) + y * cos(rad_z) + z * sin(rad_y) * sin(rad_z);
    double z_rot = -x * sin(rad_y) + z * cos(rad_y);
    *x_new = x_rot * cos(rad_z) - y_rot * sin(rad_z);
    *y_new = x_rot * sin(rad_z) + y_rot * cos(rad_z);
    *z_new = z_rot;
    *x_new = *x_new * cos(rad_x) + *z_new * sin(rad_x);
    *z_new = -*x_new * sin(rad_x) + *z_new * cos(rad_x);
}

void translate_point(double x, double y, double z, double tx, double ty, double tz, double *x_new, double *y_new, double *z_new) {
    *x_new = x + tx;
    *y_new = y + ty;
    *z_new = z + tz;
}

void scale_point(double x, double y, double z, double sx, double sy, double sz, double *x_new, double *y_new, double *z_new) {
    *x_new = x * sx;
    *y_new = y * sy;
    *z_new = z * sz;
}

void main() {
    double x = 0, y = 0, z = 0;
    double angle_x = 0, angle_y = 0, angle_z = 0;
    double tx = 0, ty = 0, tz = 0;
    double sx = 1, sy = 1, sz = 1;
    while (1) {
        double x_new, y_new, z_new;
        rotate_point(x, y, z, angle_x, angle_y, angle_z, &x_new, &y_new, &z_new);
        x = x_new; y = y_new; z = z_new;
        translate_point(x, y, z, tx, ty, tz, &x_new, &y_new, &z_new);
        x = x_new; y = y_new; z = z_new;
        scale_point(x, y, z, sx, sy, sz, &x_new, &y_new, &z_new);
        x = x_new; y = y_new; z = z_new;
        angle_x += 1;
        angle_y += 1;
        angle_z += 1;
        tx += 0.1;
        ty += 0.1;
        tz += 0.1;
        sx += 0.01;
        sy += 0.01;
        sz += 0.01;
    }
}