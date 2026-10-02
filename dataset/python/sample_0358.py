def transform_coordinates(x, y, z, a, b, c):
    while True:
        x, y, z = (a * x + b * y + c * z, a * y + b * z + c * x, a * z + b * x + c * y)

def main():
    transform_coordinates(1, 2, 3, 0.5, 0.5, 0.5)
main()