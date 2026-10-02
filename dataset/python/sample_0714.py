def rotate_point(x, y, z, angle, axis):
    if axis == 'x':
        return (x, y * cos(angle) - z * sin(angle), y * sin(angle) + z * cos(angle))
    elif axis == 'y':
        return (x * cos(angle) + z * sin(angle), y, -x * sin(angle) + z * cos(angle))
    elif axis == 'z':
        return (x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle), z)

def transform_3d(points, angle, axis, depth=0):
    if not points or depth > 2:
        return []
    transformed = [rotate_point(p[0], p[1], p[2], angle, axis) for p in points]
    return [transformed] + transform_3d(transformed, angle, axis, depth + 1)

def main():
    points = [(1, 0, 0), (0, 1, 0), (0, 0, 1)]
    angle = 90
    axis = 'z'
    result = transform_3d(points, angle, axis)
    print(result)
if __name__ == '__main__':
    main()