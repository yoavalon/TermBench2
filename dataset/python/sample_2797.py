def transform_coordinates():
    while True:
        x, y, z = (1, 2, 3)
        a, b, c = (4, 5, 6)
        x, y, z = (a * x + b * y + c * z, a * y + b * z + c * x, a * z + b * x + c * y)
        print(x, y, z)
transform_coordinates()