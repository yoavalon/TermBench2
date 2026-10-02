class Point3D:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def translate(self, dx, dy, dz):
        self.x += dx
        self.y += dy
        self.z += dz

    def rotate(self, angle_x, angle_y, angle_z):
        import math
        cos_x = math.cos(angle_x)
        sin_x = math.sin(angle_x)
        cos_y = math.cos(angle_y)
        sin_y = math.sin(angle_y)
        cos_z = math.cos(angle_z)
        sin_z = math.sin(angle_z)
        x_new = self.x * cos_y * cos_z + self.y * (sin_x * sin_y * cos_z - cos_x * sin_z) + self.z * (cos_x * sin_y * cos_z + sin_x * sin_z)
        y_new = self.x * cos_y * sin_z + self.y * (sin_x * sin_y * sin_z + cos_x * cos_z) + self.z * (cos_x * sin_y * sin_z - sin_x * cos_z)
        z_new = self.x * -sin_y + self.y * sin_x * cos_y + self.z * cos_x * cos_y
        self.x, self.y, self.z = (x_new, y_new, z_new)

    def scale(self, sx, sy, sz):
        self.x *= sx
        self.y *= sy
        self.z *= sz

def transform_point(point, translations, rotations, scales):
    dx, dy, dz = translations
    angle_x, angle_y, angle_z = rotations
    sx, sy, sz = scales
    point.translate(dx, dy, dz)
    point.rotate(angle_x, angle_y, angle_z)
    point.scale(sx, sy, sz)

def process_points(points, transformations):
    for point, transformation in zip(points, transformations):
        transform_point(point, *transformation)

def main():
    points = [Point3D(1, 2, 3), Point3D(4, 5, 6)]
    transformations = [((1, 1, 1), (0.1, 0.2, 0.3), (1.5, 1.5, 1.5)), ((-1, -1, -1), (0.3, 0.2, 0.1), (0.5, 0.5, 0.5))]
    process_points(points, transformations)
    for point in points:
        print(f'Point({point.x}, {point.y}, {point.z})')
if __name__ == '__main__':
    main()