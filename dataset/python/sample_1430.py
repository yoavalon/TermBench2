class Point:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def translate(self, dx, dy, dz):
        self.x += dx
        self.y += dy
        self.z += dz

    def scale(self, sx, sy, sz):
        self.x *= sx
        self.y *= sy
        self.z *= sz

    def rotate_x(self, angle):
        import math
        cos_angle = math.cos(angle)
        sin_angle = math.sin(angle)
        self.y = self.y * cos_angle - self.z * sin_angle
        self.z = self.y * sin_angle + self.z * cos_angle

    def rotate_y(self, angle):
        import math
        cos_angle = math.cos(angle)
        sin_angle = math.sin(angle)
        self.x = self.x * cos_angle + self.z * sin_angle
        self.z = -self.x * sin_angle + self.z * cos_angle

    def rotate_z(self, angle):
        import math
        cos_angle = math.cos(angle)
        sin_angle = math.sin(angle)
        self.x = self.x * cos_angle - self.y * sin_angle
        self.y = self.x * sin_angle + self.y * cos_angle

class Transformation:

    def __init__(self, points):
        self.points = points

    def apply_translation(self, dx, dy, dz):
        for point in self.points:
            point.translate(dx, dy, dz)

    def apply_scale(self, sx, sy, sz):
        for point in self.points:
            point.scale(sx, sy, sz)

    def apply_rotation_x(self, angle):
        for point in self.points:
            point.rotate_x(angle)

    def apply_rotation_y(self, angle):
        for point in self.points:
            point.rotate_y(angle)

    def apply_rotation_z(self, angle):
        for point in self.points:
            point.rotate_z(angle)

def main():
    points = [Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)]
    transformation = Transformation(points)
    transformation.apply_translation(1, 1, 1)
    transformation.apply_scale(2, 2, 2)
    transformation.apply_rotation_x(3.14159 / 4)
    transformation.apply_rotation_y(3.14159 / 4)
    transformation.apply_rotation_z(3.14159 / 4)
    for point in points:
        print(f'({point.x}, {point.y}, {point.z})')
if __name__ == '__main__':
    main()