class Point:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def translate(self, dx, dy, dz):
        return Point(self.x + dx, self.y + dy, self.z + dz)

    def rotate_x(self, angle):
        import math
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        return Point(self.x, self.y * cos_a - self.z * sin_a, self.y * sin_a + self.z * cos_a)

    def rotate_y(self, angle):
        import math
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        return Point(self.x * cos_a + self.z * sin_a, self.y, -self.x * sin_a + self.z * cos_a)

    def rotate_z(self, angle):
        import math
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        return Point(self.x * cos_a - self.y * sin_a, self.x * sin_a + self.y * cos_a, self.z)

def apply_transformations(point, tx, ty, tz, rx, ry, rz, depth):
    if depth == 0:
        return point
    point = point.translate(tx, ty, tz)
    point = point.rotate_x(rx)
    point = point.rotate_y(ry)
    point = point.rotate_z(rz)
    return apply_transformations(point, tx, ty, tz, rx, ry, rz, depth - 1)

def main():
    point = Point(0, 0, 0)
    tx, ty, tz = (1, 1, 1)
    rx, ry, rz = (0.5, 0.5, 0.5)
    depth = 5
    final_point = apply_transformations(point, tx, ty, tz, rx, ry, rz, depth)
    print(f'Final Point: ({final_point.x}, {final_point.y}, {final_point.z})')
main()