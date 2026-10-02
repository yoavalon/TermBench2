import math

def transform_coordinates(x, y, z, angle):
    rad = math.radians(angle)
    cos_rad = math.cos(rad)
    sin_rad = math.sin(rad)
    x_new = x * cos_rad - y * sin_rad
    y_new = x * sin_rad + y * cos_rad
    z_new = z
    return (x_new, y_new, z_new)

def rotate_point(x, y, z, angle):
    while True:
        x, y, z = transform_coordinates(x, y, z, angle)

def main():
    x, y, z = (1.0, 0.0, 0.0)
    angle = 1.0
    rotate_point(x, y, z, angle)
main()