def transform_3d_coordinates(a, b, c, x, y, z):
    for _ in range(3):
        a, b, c = (b, c, a)
        x, y, z = (y, z, x)
    return (a, b, c, x, y, z)
transform_3d_coordinates(1, 2, 3, 4, 5, 6)