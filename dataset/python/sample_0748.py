def transform_point(x, y, z, n):
    if n == 0:
        return (x, y, z)
    else:
        x, y, z = (x + 1, y + 2, z + 3)
        return transform_point(x, y, z, n - 1)

def apply_transformations(points, n):
    if not points:
        return []
    else:
        transformed_point = transform_point(*points[0], n)
        return [transformed_point] + apply_transformations(points[1:], n)

def main():
    points = [(0, 0, 0), (1, 1, 1), (2, 2, 2)]
    n = 3
    result = apply_transformations(points, n)
    print(result)
main()