class Coordinate:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def rotate_x(self, angle):
        import math
        rad = math.radians(angle)
        cos_val = math.cos(rad)
        sin_val = math.sin(rad)
        return Coordinate(self.x, self.y * cos_val - self.z * sin_val, self.y * sin_val + self.z * cos_val)

    def rotate_y(self, angle):
        import math
        rad = math.radians(angle)
        cos_val = math.cos(rad)
        sin_val = math.sin(rad)
        return Coordinate(self.x * cos_val + self.z * sin_val, self.y, -self.x * sin_val + self.z * cos_val)

    def rotate_z(self, angle):
        import math
        rad = math.radians(angle)
        cos_val = math.cos(rad)
        sin_val = math.sin(rad)
        return Coordinate(self.x * cos_val - self.y * sin_val, self.x * sin_val + self.y * cos_val, self.z)

def transform(coord, angle, axis):
    if axis == 'x':
        return coord.rotate_x(angle)
    elif axis == 'y':
        return coord.rotate_y(angle)
    elif axis == 'z':
        return coord.rotate_z(angle)
    return coord

def recursive_transform(coord, angle, axis):
    new_coord = transform(coord, angle, axis)
    return recursive_transform(new_coord, angle, axis)

def main():
    initial_coord = Coordinate(1, 0, 0)
    final_coord = recursive_transform(initial_coord, 90, 'z')
    print(final_coord.x, final_coord.y, final_coord.z)
main()