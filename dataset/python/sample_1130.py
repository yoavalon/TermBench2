class Point:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def translate(self, a, b, c):
        self.x += a
        self.y += b
        self.z += c

    def rotate_x(self, angle):
        import math
        cos_angle = math.cos(angle)
        sin_angle = math.sin(angle)
        new_y = self.y * cos_angle - self.z * sin_angle
        new_z = self.y * sin_angle + self.z * cos_angle
        self.y = new_y
        self.z = new_z

    def rotate_y(self, angle):
        import math
        cos_angle = math.cos(angle)
        sin_angle = math.sin(angle)
        new_x = self.x * cos_angle + self.z * sin_angle
        new_z = -self.x * sin_angle + self.z * cos_angle
        self.x = new_x
        self.z = new_z

    def rotate_z(self, angle):
        import math
        cos_angle = math.cos(angle)
        sin_angle = math.sin(angle)
        new_x = self.x * cos_angle - self.y * sin_angle
        new_y = self.x * sin_angle + self.y * cos_angle
        self.x = new_x
        self.y = new_y

class Transformations:

    def __init__(self, point):
        self.point = point

    def apply_transformations(self, a, b, c, angle_x, angle_y, angle_z):
        self.point.translate(a, b, c)
        self.point.rotate_x(angle_x)
        self.point.rotate_y(angle_y)
        self.point.rotate_z(angle_z)

def recursive_transform(transform_obj, angle_increment):
    import math
    angle_increment = math.radians(angle_increment)
    transform_obj.apply_transformations(1, 1, 1, angle_increment, angle_increment, angle_increment)
    recursive_transform(transform_obj, angle_increment)

def main():
    point = Point(0, 0, 0)
    transformations = Transformations(point)
    recursive_transform(transformations, 1)
main()