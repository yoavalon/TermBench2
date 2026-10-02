import math

class Point3D:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def distance(self, other):
        return math.sqrt((self.x - other.x) ** 2 + (self.y - other.y) ** 2 + (self.z - other.z) ** 2)

    def rotate(self, angle_x, angle_y, angle_z):
        cos_x, sin_x = (math.cos(angle_x), math.sin(angle_x))
        cos_y, sin_y = (math.cos(angle_y), math.sin(angle_y))
        cos_z, sin_z = (math.cos(angle_z), math.sin(angle_z))
        x = self.x
        y = self.y
        z = self.z
        self.x = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z)
        self.y = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z)
        self.z = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y

class Transformation:

    def __init__(self, angle_x, angle_y, angle_z):
        self.angle_x = angle_x
        self.angle_y = angle_y
        self.angle_z = angle_z

    def apply(self, point):
        point.rotate(self.angle_x, self.angle_y, self.angle_z)

def simulate_transformation():
    point = Point3D(1.0, 1.0, 1.0)
    transformation = Transformation(math.pi / 4, math.pi / 4, math.pi / 4)
    while True:
        transformation.apply(point)
        print(f'({point.x:.10f}, {point.y:.10f}, {point.z:.10f})')
simulate_transformation()