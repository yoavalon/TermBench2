def transform_coordinates(x, y, z, a, b, c):
    while True:
        x, y, z = (x + a, y + b, z + c)
        print(f'({x}, {y}, {z})')
transform_coordinates(0, 0, 0, 1, 1, 1)