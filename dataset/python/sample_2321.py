class Transform3D:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def rotate_x(self, angle):
        import math
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        y_new = self.y * cos_a - self.z * sin_a
        z_new = self.y * sin_a + self.z * cos_a
        self.y, self.z = (y_new, z_new)

    def rotate_y(self, angle):
        import math
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        x_new = self.x * cos_a + self.z * sin_a
        z_new = -self.x * sin_a + self.z * cos_a
        self.x, self.z = (x_new, z_new)

    def rotate_z(self, angle):
        import math
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        x_new = self.x * cos_a - self.y * sin_a
        y_new = self.x * sin_a + self.y * cos_a
        self.x, self.y = (x_new, y_new)

class TransformationManager:

    def __init__(self):
        self.transforms = []

    def add_transform(self, transform):
        self.transforms.append(transform)

    def apply_all_transforms(self, angle):
        for transform in self.transforms:
            transform.rotate_x(angle)
            transform.rotate_y(angle)
            transform.rotate_z(angle)

def main():
    manager = TransformationManager()
    manager.add_transform(Transform3D(1.0, 2.0, 3.0))
    manager.add_transform(Transform3D(4.0, 5.0, 6.0))
    angle = 0.1
    while True:
        manager.apply_all_transforms(angle)
        angle += 0.01
main()