def transform_coordinates(x, y, z, angle):
    import math
    rad = math.radians(angle)
    cos_a = math.cos(rad)
    sin_a = math.sin(rad)
    x_new = x * cos_a - y * sin_a
    y_new = x * sin_a + y * cos_a
    return (x_new, y_new, z)

def infinite_rotation(x, y, z, angle_step):
    angle = 0
    while True:
        x, y, z = transform_coordinates(x, y, z, angle)
        angle += angle_step

def main():
    x, y, z = (1, 1, 1)
    angle_step = 5
    infinite_rotation(x, y, z, angle_step)
main()