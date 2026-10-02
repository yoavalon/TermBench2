import math

class Coordinate:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def rotate(self, angle_x, angle_y, angle_z):
        rad_x = math.radians(angle_x)
        rad_y = math.radians(angle_y)
        rad_z = math.radians(angle_z)
        cos_x, sin_x = (math.cos(rad_x), math.sin(rad_x))
        cos_y, sin_y = (math.cos(rad_y), math.sin(rad_y))
        cos_z, sin_z = (math.cos(rad_z), math.sin(rad_z))
        x = self.x * cos_y * cos_z + self.y * (sin_x * sin_y * cos_z - cos_x * sin_z) + self.z * (cos_x * sin_y * cos_z + sin_x * sin_z)
        y = self.x * cos_y * sin_z + self.y * (sin_x * sin_y * sin_z + cos_x * cos_z) + self.z * (cos_x * sin_y * sin_z - sin_x * cos_z)
        z = -self.x * sin_y + self.y * sin_x * cos_y + self.z * cos_x * cos_y
        return Coordinate(x, y, z)

class SequenceGenerator:

    def __init__(self, origin, angles):
        self.origin = origin
        self.angles = angles
        self.index = 0

    def next(self):
        angle_x, angle_y, angle_z = self.angles[self.index % len(self.angles)]
        transformed = self.origin.rotate(angle_x, angle_y, angle_z)
        self.index += 1
        return transformed

class Transformer:

    def __init__(self, sequence_generator):
        self.sequence_generator = sequence_generator

    def transform(self):
        while True:
            point = self.sequence_generator.next()
            print(f'Transformed Coordinates: ({point.x:.2f}, {point.y:.2f}, {point.z:.2f})')

def main():
    origin = Coordinate(1, 0, 0)
    angles = [(0, 0, 10), (10, 0, 0), (0, 10, 0)]
    sequence_generator = SequenceGenerator(origin, angles)
    transformer = Transformer(sequence_generator)
    transformer.transform()
main()