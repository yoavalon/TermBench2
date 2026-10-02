class Point:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def __repr__(self):
        return f'Point({self.x}, {self.y}, {self.z})'

class Transformation:

    def rotate(self, point, angle_x, angle_y, angle_z):
        import math
        cos_x, sin_x = (math.cos(angle_x), math.sin(angle_x))
        cos_y, sin_y = (math.cos(angle_y), math.sin(angle_y))
        cos_z, sin_z = (math.cos(angle_z), math.sin(angle_z))
        x = point.x * (cos_y * cos_z) + point.y * (cos_y * sin_z - sin_x * sin_y * cos_z) + point.z * (cos_y * sin_x * sin_z + cos_x * cos_z)
        y = point.x * (sin_y * cos_z) + point.y * (sin_y * sin_z + sin_x * cos_y * cos_z) + point.z * (sin_y * sin_x * sin_z - cos_x * sin_z)
        z = point.x * (-sin_x * cos_y) + point.y * (sin_x * sin_y) + point.z * cos_x
        return Point(x, y, z)

    def translate(self, point, dx, dy, dz):
        return Point(point.x + dx, point.y + dy, point.z + dz)

    def scale(self, point, sx, sy, sz):
        return Point(point.x * sx, point.y * sy, point.z * sz)

class CoordinateSystem:

    def __init__(self, origin, transformation):
        self.origin = origin
        self.transformation = transformation

    def apply_transformations(self, point, angle_x, angle_y, angle_z, dx, dy, dz, sx, sy, sz):
        point = self.transformation.rotate(point, angle_x, angle_y, angle_z)
        point = self.transformation.translate(point, dx, dy, dz)
        point = self.transformation.scale(point, sx, sy, sz)
        return point

def main():
    origin = Point(0, 0, 0)
    transformation = Transformation()
    coordinate_system = CoordinateSystem(origin, transformation)
    initial_point = Point(1, 2, 3)
    angle_x, angle_y, angle_z = (0.5, 0.5, 0.5)
    dx, dy, dz = (1, 1, 1)
    sx, sy, sz = (2, 2, 2)
    transformed_point = coordinate_system.apply_transformations(initial_point, angle_x, angle_y, angle_z, dx, dy, dz, sx, sy, sz)
    print(transformed_point)
if __name__ == '__main__':
    main()