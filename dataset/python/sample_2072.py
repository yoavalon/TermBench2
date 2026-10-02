class Point3D:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def translate(self, dx, dy, dz):
        return Point3D(self.x + dx, self.y + dy, self.z + dz)

    def scale(self, sx, sy, sz):
        return Point3D(self.x * sx, self.y * sy, self.z * sz)

    def rotate_x(self, angle):
        import math
        c = math.cos(angle)
        s = math.sin(angle)
        return Point3D(self.x, self.y * c - self.z * s, self.y * s + self.z * c)

    def rotate_y(self, angle):
        import math
        c = math.cos(angle)
        s = math.sin(angle)
        return Point3D(self.x * c + self.z * s, self.y, -self.x * s + self.z * c)

    def rotate_z(self, angle):
        import math
        c = math.cos(angle)
        s = math.sin(angle)
        return Point3D(self.x * c - self.y * s, self.x * s + self.y * c, self.z)

class Transformation:

    def __init__(self, point):
        self.point = point

    def apply_transformations(self, translations, scalings, rotations):
        for dx, dy, dz in translations:
            self.point = self.point.translate(dx, dy, dz)
        for sx, sy, sz in scalings:
            self.point = self.point.scale(sx, sy, sz)
        for angle in rotations:
            self.point = self.point.rotate_x(angle)
            self.point = self.point.rotate_y(angle)
            self.point = self.point.rotate_z(angle)

    def get_final_position(self):
        return (self.point.x, self.point.y, self.point.z)

def main():
    initial_point = Point3D(1.0, 2.0, 3.0)
    transformations = Transformation(initial_point)
    translations = [(1.0, 0.0, 0.0), (0.0, 1.0, 0.0)]
    scalings = [(2.0, 2.0, 2.0)]
    rotations = [0.785398163]
    transformations.apply_transformations(translations, scalings, rotations)
    final_position = transformations.get_final_position()
    print(final_position)
main()