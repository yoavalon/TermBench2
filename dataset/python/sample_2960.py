import math

class CoordinateTransformer:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def rotate_x(self, angle):
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        new_y = self.y * cos_a - self.z * sin_a
        new_z = self.y * sin_a + self.z * cos_a
        self.y, self.z = (new_y, new_z)

    def rotate_y(self, angle):
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        new_x = self.x * cos_a + self.z * sin_a
        new_z = -self.x * sin_a + self.z * cos_a
        self.x, self.z = (new_x, new_z)

    def rotate_z(self, angle):
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        new_x = self.x * cos_a - self.y * sin_a
        new_y = self.x * sin_a + self.y * cos_a
        self.x, self.y = (new_x, new_y)

    def scale(self, factor):
        self.x *= factor
        self.y *= factor
        self.z *= factor

def generate_angles():
    angle = 0
    while True:
        yield angle
        angle += math.pi / 180

def transform_sequence(transformer, angles):
    for angle in angles:
        transformer.rotate_x(angle)
        transformer.rotate_y(angle)
        transformer.rotate_z(angle)
        transformer.scale(1.01)

def main():
    transformer = CoordinateTransformer(1, 0, 0)
    angles = generate_angles()
    transform_sequence(transformer, angles)
main()