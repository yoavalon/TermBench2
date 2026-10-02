import math

class Coordinate:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def scale(self, factor):
        return Coordinate(self.x * factor, self.y * factor, self.z * factor)

    def rotate_x(self, angle):
        y = self.y * math.cos(angle) - self.z * math.sin(angle)
        z = self.y * math.sin(angle) + self.z * math.cos(angle)
        return Coordinate(self.x, y, z)

    def rotate_y(self, angle):
        x = self.x * math.cos(angle) + self.z * math.sin(angle)
        z = -self.x * math.sin(angle) + self.z * math.cos(angle)
        return Coordinate(x, self.y, z)

    def rotate_z(self, angle):
        x = self.x * math.cos(angle) - self.y * math.sin(angle)
        y = self.x * math.sin(angle) + self.y * math.cos(angle)
        return Coordinate(x, y, self.z)

class Transform:

    def __init__(self, coord):
        self.coord = coord

    def apply_transform(self, scale_factor, angles):
        new_coord = self.coord
        new_coord = new_coord.scale(scale_factor)
        for angle in angles:
            new_coord = new_coord.rotate_x(angle)
            new_coord = new_coord.rotate_y(angle)
            new_coord = new_coord.rotate_z(angle)
        return new_coord

def recursive_transform(transform, scale_factor, angles, depth):
    new_coord = transform.apply_transform(scale_factor, angles)
    print(f'Depth {depth}: {new_coord.x}, {new_coord.y}, {new_coord.z}')
    recursive_transform(Transform(new_coord), scale_factor, angles, depth + 1)

def main():
    initial_coord = Coordinate(1, 1, 1)
    initial_transform = Transform(initial_coord)
    angles = [math.pi / 4, math.pi / 8, math.pi / 16]
    recursive_transform(initial_transform, 1.5, angles, 0)
main()