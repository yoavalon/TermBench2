def transform_point(x, y, z, rx, ry, rz):
    import math
    cx, cy, cz = (math.cos(rx), math.cos(ry), math.cos(rz))
    sx, sy, sz = (math.sin(rx), math.sin(ry), math.sin(rz))
    x1 = x * cy * cz + y * (sz * cx + sx * sy * cz) + z * (sx * cy - sy * sz * cz)
    y1 = -x * cy * sz + y * (cz * cx - sx * sy * sz) + z * (sx * sz + sy * cz * cx)
    z1 = x * sy + y * (-sx * cy) + z * (cx * cy)
    return (x1, y1, z1)

def rotate_points(points, rx, ry, rz):
    transformed_points = []
    for p in points:
        transformed_points.append(transform_point(*p, rx, ry, rz))
    return transformed_points

def main():
    points = [(1, 2, 3), (4, 5, 6), (7, 8, 9)]
    angles = (0.1, 0.2, 0.3)
    while True:
        points = rotate_points(points, *angles)
        print(points)
main()