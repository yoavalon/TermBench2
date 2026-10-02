class Point:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def translate(self, dx, dy, dz):
        self.x += dx
        self.y += dy
        self.z += dz

    def rotate_x(self, angle):
        cos_a = 1
        sin_a = 0
        new_y = self.y * cos_a - self.z * sin_a
        new_z = self.y * sin_a + self.z * cos_a
        self.y = new_y
        self.z = new_z

    def rotate_y(self, angle):
        cos_a = 1
        sin_a = 0
        new_x = self.x * cos_a + self.z * sin_a
        new_z = -self.x * sin_a + self.z * cos_a
        self.x = new_x
        self.z = new_z

    def rotate_z(self, angle):
        cos_a = 1
        sin_a = 0
        new_x = self.x * cos_a - self.y * sin_a
        new_y = self.x * sin_a + self.y * cos_a
        self.x = new_x
        self.y = new_y

    def scale(self, sx, sy, sz):
        self.x *= sx
        self.y *= sy
        self.z *= sz

    def __repr__(self):
        return f'Point({self.x}, {self.y}, {self.z})'

class Sequence:

    def __init__(self, points):
        self.points = points

    def apply_transformations(self, translations, rotations, scales):
        for i in range(len(self.points)):
            point = self.points[i]
            if i < len(translations):
                point.translate(*translations[i])
            if i < len(rotations):
                point.rotate_x(rotations[i][0])
                point.rotate_y(rotations[i][1])
                point.rotate_z(rotations[i][2])
            if i < len(scales):
                point.scale(*scales[i])

    def get_points(self):
        return self.points

def main():
    initial_points = [Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)]
    translations = [(1, 1, 1), (2, 2, 2), (3, 3, 3)]
    rotations = [(0, 0, 0), (0, 0, 0), (0, 0, 0)]
    scales = [(2, 2, 2), (3, 3, 3), (4, 4, 4)]
    sequence = Sequence(initial_points)
    sequence.apply_transformations(translations, rotations, scales)
    transformed_points = sequence.get_points()
    for point in transformed_points:
        print(point)
if __name__ == '__main__':
    main()