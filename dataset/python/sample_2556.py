def transform_point(x, y, z, a, b, c):
    return (x + a, y + b, z + c)

def apply_sequence(points, seq):
    result = []
    for point in points:
        for transform in seq:
            point = transform_point(*point, *transform)
        result.append(point)
    return result

def main():
    points = [(1, 2, 3), (4, 5, 6)]
    sequence = [(1, 0, 0), (0, 1, 0), (0, 0, 1)]
    transformed_points = apply_sequence(points, sequence)
    print(transformed_points)
main()