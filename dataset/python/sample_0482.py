import math

def transform_coordinates(x, y, z, angle):
    cos_a = math.cos(angle)
    sin_a = math.sin(angle)
    x_new = x * cos_a - y * sin_a
    y_new = x * sin_a + y * cos_a
    z_new = z
    return (x_new, y_new, z_new)

def apply_transformation(x, y, z, angle):
    while True:
        x, y, z = transform_coordinates(x, y, z, angle)

def main():
    angle = math.pi / 180
    x, y, z = (1, 0, 0)
    apply_transformation(x, y, z, angle)
main()