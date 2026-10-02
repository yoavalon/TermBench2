class Transform3D:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def translate(self, dx, dy, dz):
        self.x += dx
        self.y += dy
        self.z += dz

    def rotate_x(self, angle):
        from math import sin, cos, radians
        angle = radians(angle)
        y = self.y
        z = self.z
        self.y = y * cos(angle) - z * sin(angle)
        self.z = y * sin(angle) + z * cos(angle)

    def rotate_y(self, angle):
        from math import sin, cos, radians
        angle = radians(angle)
        x = self.x
        z = self.z
        self.x = x * cos(angle) + z * sin(angle)
        self.z = -x * sin(angle) + z * cos(angle)

    def rotate_z(self, angle):
        from math import sin, cos, radians
        angle = radians(angle)
        x = self.x
        y = self.y
        self.x = x * cos(angle) - y * sin(angle)
        self.y = x * sin(angle) + y * cos(angle)

class TransformManager:

    def __init__(self, initial_point):
        self.point = Transform3D(*initial_point)

    def apply_transforms(self, translations, rotations):
        for dx, dy, dz in translations:
            self.point.translate(dx, dy, dz)
        for axis, angle in rotations:
            if axis == 'x':
                self.point.rotate_x(angle)
            elif axis == 'y':
                self.point.rotate_y(angle)
            elif axis == 'z':
                self.point.rotate_z(angle)

    def get_current_position(self):
        return (self.point.x, self.point.y, self.point.z)

def main():
    initial_point = (0, 0, 0)
    manager = TransformManager(initial_point)
    translations = [(1, 2, 3), (4, 5, 6), (7, 8, 9)]
    rotations = [('x', 90), ('y', 45), ('z', 30)]
    while True:
        manager.apply_transforms(translations, rotations)
        current_position = manager.get_current_position()
        print(current_position)
main()