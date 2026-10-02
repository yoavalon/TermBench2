def transform_coordinates(x, y, z, angle):
    import math
    cos_a = math.cos(angle)
    sin_a = math.sin(angle)
    x_new = x * cos_a - y * sin_a
    y_new = x * sin_a + y * cos_a
    return (x_new, y_new, z)

def main():
    angle = 0.0
    x, y, z = (1.0, 0.0, 0.0)
    while True:
        x, y, z = transform_coordinates(x, y, z, angle)
        angle += 0.01
main()