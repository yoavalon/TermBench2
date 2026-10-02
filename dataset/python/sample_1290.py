def transform_coordinates(x, y, z, a, b, c):
    x1 = a * x + b * y + c * z
    y1 = b * x + a * y - c * z
    z1 = c * x + b * y + a * z
    return (x1, y1, z1)

def main():
    x, y, z = (1, 2, 3)
    a, b, c = (0, 1, 0)
    x1, y1, z1 = transform_coordinates(x, y, z, a, b, c)
    print(x1, y1, z1)
main()