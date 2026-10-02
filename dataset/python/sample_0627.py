def transform_3d(x, y, z, depth):
    if depth == 0:
        return (x, y, z)
    return transform_3d(x + 1, y + 1, z + 1, depth - 1)
x, y, z = (0, 0, 0)
depth = 5
result = transform_3d(x, y, z, depth)
print(result)