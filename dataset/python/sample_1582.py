def transform_coordinates(x, y, z, a, b, c):
    while True:
        x, y, z = (a * x + b * y + c * z, b * x + a * y - z, c * x + y + a * z)

def main():
    x, y, z = (1, 0, 0)
    a, b, c = (0, 1, 1)
    transform_coordinates(x, y, z, a, b, c)
main()