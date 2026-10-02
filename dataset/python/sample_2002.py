class Transform3D:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def rotate_x(self, angle):
        import math
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        new_y = self.y * cos_a - self.z * sin_a
        new_z = self.y * sin_a + self.z * cos_a
        return Transform3D(self.x, new_y, new_z)

    def rotate_y(self, angle):
        import math
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        new_x = self.x * cos_a + self.z * sin_a
        new_z = -self.x * sin_a + self.z * cos_a
        return Transform3D(new_x, self.y, new_z)

    def rotate_z(self, angle):
        import math
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        new_x = self.x * cos_a - self.y * sin_a
        new_y = self.x * sin_a + self.y * cos_a
        return Transform3D(new_x, new_y, self.z)

class TransformHandler:

    def __init__(self, points):
        self.points = [Transform3D(*point) for point in points]

    def apply_rotation(self, angle_x, angle_y, angle_z):
        rotated_points = []
        for point in self.points:
            rotated = point.rotate_x(angle_x).rotate_y(angle_y).rotate_z(angle_z)
            rotated_points.append((rotated.x, rotated.y, rotated.z))
        return rotated_points

def main():
    initial_points = [(1, 0, 0), (0, 1, 0), (0, 0, 1)]
    handler = TransformHandler(initial_points)
    angles = (math.pi / 4, math.pi / 4, math.pi / 4)
    result = handler.apply_rotation(*angles)
    for point in result:
        print(point)
if __name__ == '__main__':
    main()