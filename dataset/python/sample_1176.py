class Point3D:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def translate(self, dx, dy, dz):
        self.x += dx
        self.y += dy
        self.z += dz

    def rotate_x(self, angle):
        import math
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        y = self.y * cos_a - self.z * sin_a
        z = self.y * sin_a + self.z * cos_a
        self.y = y
        self.z = z

    def rotate_y(self, angle):
        import math
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        x = self.x * cos_a + self.z * sin_a
        z = -self.x * sin_a + self.z * cos_a
        self.x = x
        self.z = z

    def rotate_z(self, angle):
        import math
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        x = self.x * cos_a - self.y * sin_a
        y = self.x * sin_a + self.y * cos_a
        self.x = x
        self.y = y

def transform_point(point, angles, translations):
    point.rotate_x(angles[0])
    point.rotate_y(angles[1])
    point.rotate_z(angles[2])
    point.translate(translations[0], translations[1], translations[2])

def recursive_transform(point, angles, translations):
    transform_point(point, angles, translations)
    recursive_transform(point, angles, translations)

def main():
    p = Point3D(1, 0, 0)
    a = [0.1, 0.2, 0.3]
    t = [0.1, 0.1, 0.1]
    recursive_transform(p, a, t)
main()