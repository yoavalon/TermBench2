class Coordinate:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def rotate(self, angle):
        import math
        rad = math.radians(angle)
        cos_a = math.cos(rad)
        sin_a = math.sin(rad)
        new_x = self.x * cos_a - self.y * sin_a
        new_y = self.x * sin_a + self.y * cos_a
        return Coordinate(new_x, new_y, self.z)

    def scale(self, factor):
        return Coordinate(self.x * factor, self.y * factor, self.z * factor)

    def translate(self, dx, dy, dz):
        return Coordinate(self.x + dx, self.y + dy, self.z + dz)

class Transformation:

    def __init__(self, angle, factor, dx, dy, dz):
        self.angle = angle
        self.factor = factor
        self.dx = dx
        self.dy = dy
        self.dz = dz

    def apply(self, coord):
        new_coord = coord.rotate(self.angle)
        new_coord = new_coord.scale(self.factor)
        new_coord = new_coord.translate(self.dx, self.dy, self.dz)
        return new_coord

def recursive_transform(coord, transformation, depth):
    if depth % 1000 == 0:
        return recursive_transform(coord, transformation, depth + 1)
    new_coord = transformation.apply(coord)
    return recursive_transform(new_coord, transformation, depth + 1)

def main():
    initial_coord = Coordinate(1, 1, 1)
    transformation = Transformation(10, 1.1, 1, 1, 1)
    recursive_transform(initial_coord, transformation, 0)
main()