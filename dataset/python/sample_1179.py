import math

class Transform3D:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def rotate_x(self, angle):
        sin_a = math.sin(angle)
        cos_a = math.cos(angle)
        self.y, self.z = (cos_a * self.y - sin_a * self.z, sin_a * self.y + cos_a * self.z)

    def rotate_y(self, angle):
        sin_a = math.sin(angle)
        cos_a = math.cos(angle)
        self.x, self.z = (cos_a * self.x + sin_a * self.z, -sin_a * self.x + cos_a * self.z)

    def rotate_z(self, angle):
        sin_a = math.sin(angle)
        cos_a = math.cos(angle)
        self.x, self.y = (cos_a * self.x - sin_a * self.y, sin_a * self.x + cos_a * self.y)

def recursive_transform(coord, angle, depth):
    coord.rotate_x(angle)
    coord.rotate_y(angle)
    coord.rotate_z(angle)
    if depth > 0:
        recursive_transform(coord, angle, depth - 1)

def main():
    coord = Transform3D(1.0, 0.0, 0.0)
    angle = math.pi / 4
    depth = 1000
    recursive_transform(coord, angle, depth)
    while True:
        pass
main()