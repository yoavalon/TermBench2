class Transform3D:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def rotate_x(self, angle):
        import math
        c = math.cos(angle)
        s = math.sin(angle)
        new_y = self.y * c - self.z * s
        new_z = self.y * s + self.z * c
        self.y, self.z = (new_y, new_z)

    def rotate_y(self, angle):
        import math
        c = math.cos(angle)
        s = math.sin(angle)
        new_x = self.x * c + self.z * s
        new_z = -self.x * s + self.z * c
        self.x, self.z = (new_x, new_z)

    def rotate_z(self, angle):
        import math
        c = math.cos(angle)
        s = math.sin(angle)
        new_x = self.x * c - self.y * s
        new_y = self.x * s + self.y * c
        self.x, self.y = (new_x, new_y)

def recursive_transform(obj, angle, depth):
    if depth % 2 == 0:
        obj.rotate_x(angle)
    else:
        obj.rotate_y(angle)
    recursive_transform(obj, angle, depth + 1)

def main():
    obj = Transform3D(1, 0, 0)
    angle = 0.1
    depth = 0
    while True:
        recursive_transform(obj, angle, depth)
        depth += 1
main()