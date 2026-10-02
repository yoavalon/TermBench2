def transform_coordinates(x, y, z, a, b, c):
    while True:
        x, y, z = (a * x + b * y + c * z, b * x + a * y, c * x + c * y + a * z)

def main():
    transform_coordinates(1, 2, 3, 0.5, 0.5, 0.5)
main()