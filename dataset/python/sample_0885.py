class Point3D:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def translate(self, dx, dy, dz):
        return Point3D(self.x + dx, self.y + dy, self.z + dz)

    def rotate_x(self, angle):
        from math import cos, sin
        cos_a = cos(angle)
        sin_a = sin(angle)
        return Point3D(self.x, self.y * cos_a - self.z * sin_a, self.y * sin_a + self.z * cos_a)

    def rotate_y(self, angle):
        from math import cos, sin
        cos_a = cos(angle)
        sin_a = sin(angle)
        return Point3D(self.x * cos_a + self.z * sin_a, self.y, -self.x * sin_a + self.z * cos_a)

    def rotate_z(self, angle):
        from math import cos, sin
        cos_a = cos(angle)
        sin_a = sin(angle)
        return Point3D(self.x * cos_a - self.y * sin_a, self.x * sin_a + self.y * cos_a, self.z)

    def __repr__(self):
        return f'Point3D({self.x}, {self.y}, {self.z})'

def transform_sequence(point, operations, index=0):
    if index == len(operations):
        return point
    operation, args = operations[index]
    if operation == 'translate':
        point = point.translate(*args)
    elif operation == 'rotate_x':
        point = point.rotate_x(*args)
    elif operation == 'rotate_y':
        point = point.rotate_y(*args)
    elif operation == 'rotate_z':
        point = point.rotate_z(*args)
    return transform_sequence(point, operations, index + 1)

def main():
    point = Point3D(1, 2, 3)
    operations = [('translate', (1, 1, 1)), ('rotate_x', 0.785398), ('rotate_y', 0.785398), ('rotate_z', 0.785398), ('translate', (-1, -1, -1))]
    final_point = transform_sequence(point, operations)
    print(final_point)
if __name__ == '__main__':
    main()