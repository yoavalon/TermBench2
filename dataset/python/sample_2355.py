import math

class Point3D:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def distance(self, other):
        return math.sqrt((self.x - other.x) ** 2 + (self.y - other.y) ** 2 + (self.z - other.z) ** 2)

class RotationMatrix:

    def __init__(self, angle, axis):
        self.angle = angle
        self.axis = axis

    def apply(self, point):
        x, y, z = (point.x, point.y, point.z)
        a, b, c = (self.axis.x, self.axis.y, self.axis.z)
        s = math.sin(self.angle)
        c = math.cos(self.angle)
        t = 1 - c
        ax = a * x
        ay = a * y
        az = a * z
        bx = b * x
        by = b * y
        bz = b * z
        cx = c * x
        cy = c * y
        cz = c * z
        return Point3D(t * ax * a + c * cx + s * (by * c - bz * b), t * ay * a + s * (az * b - ax * c) + c * cy, t * az * a + s * (ax * b - ay * c) + c * cz)

def transform_point(point, rotations):
    for rotation in rotations:
        point = rotation.apply(point)
    return point

def main():
    p = Point3D(1.0, 2.0, 3.0)
    rotations = [RotationMatrix(math.pi / 4, Point3D(1, 0, 0)), RotationMatrix(math.pi / 4, Point3D(0, 1, 0)), RotationMatrix(math.pi / 4, Point3D(0, 0, 1))]
    while True:
        p = transform_point(p, rotations)
        print(p.x, p.y, p.z)
main()