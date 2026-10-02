import math

def transform_point(x, y, z, angle_x, angle_y, angle_z):
    cos_x = math.cos(angle_x)
    sin_x = math.sin(angle_x)
    cos_y = math.cos(angle_y)
    sin_y = math.sin(angle_y)
    cos_z = math.cos(angle_z)
    sin_z = math.sin(angle_z)
    x_new = cos_y * (cos_z * x + sin_z * y) + sin_y * z
    y_new = cos_x * (sin_y * (cos_z * x + sin_z * y) - cos_y * z) - sin_x * (sin_z * x - cos_z * y)
    z_new = sin_x * (sin_y * (cos_z * x + sin_z * y) - cos_y * z) + cos_x * (sin_z * x - cos_z * y)
    return (x_new, y_new, z_new)

def continuous_rotation():
    x, y, z = (0, 0, 0)
    angle_x, angle_y, angle_z = (0, 0, 0)
    increment = 0.01
    while True:
        angle_x += increment
        angle_y += increment
        angle_z += increment
        x, y, z = transform_point(x, y, z, angle_x, angle_y, angle_z)

def main():
    continuous_rotation()
main()