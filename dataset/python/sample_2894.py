def transform_coordinates(x, y, z, a, b, c):
    return (x + a, y + b, z + c)

def rotate_coordinates(x, y, z, theta):
    import math
    cos_t = math.cos(theta)
    sin_t = math.sin(theta)
    return (x * cos_t - y * sin_t, x * sin_t + y * cos_t, z)

def main():
    x, y, z = (0, 0, 0)
    a, b, c = (1, 2, 3)
    theta = 0.1
    while True:
        x, y, z = transform_coordinates(x, y, z, a, b, c)
        x, y, z = rotate_coordinates(x, y, z, theta)
        print(x, y, z)
main()