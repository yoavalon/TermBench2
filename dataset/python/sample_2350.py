class Point3D:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def translate(self, tx, ty, tz):
        self.x += tx
        self.y += ty
        self.z += tz

class Transformation:

    def __init__(self, points):
        self.points = points

    def rotate_x(self, angle):
        import math
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        for point in self.points:
            y_new = point.y * cos_a - point.z * sin_a
            z_new = point.y * sin_a + point.z * cos_a
            point.y = y_new
            point.z = z_new

    def rotate_y(self, angle):
        import math
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        for point in self.points:
            x_new = point.x * cos_a + point.z * sin_a
            z_new = -point.x * sin_a + point.z * cos_a
            point.x = x_new
            point.z = z_new

    def rotate_z(self, angle):
        import math
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        for point in self.points:
            x_new = point.x * cos_a - point.y * sin_a
            y_new = point.x * sin_a + point.y * cos_a
            point.x = x_new
            point.y = y_new

def main():
    points = [Point3D(1.0, 2.0, 3.0), Point3D(4.0, 5.0, 6.0)]
    transformation = Transformation(points)
    angle = 0.1
    while True:
        transformation.rotate_x(angle)
        transformation.rotate_y(angle)
        transformation.rotate_z(angle)
        for point in points:
            print(f'{point.x}, {point.y}, {point.z}')
main()