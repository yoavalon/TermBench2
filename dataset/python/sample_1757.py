class CoordinateTransform:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def translate(self, dx, dy, dz):
        self.x += dx
        self.y += dy
        self.z += dz

    def rotate_x(self, angle):
        import math
        rad = math.radians(angle)
        self.y, self.z = (self.y * math.cos(rad) - self.z * math.sin(rad), self.y * math.sin(rad) + self.z * math.cos(rad))

    def rotate_y(self, angle):
        import math
        rad = math.radians(angle)
        self.x, self.z = (self.x * math.cos(rad) + self.z * math.sin(rad), -self.x * math.sin(rad) + self.z * math.cos(rad))

    def rotate_z(self, angle):
        import math
        rad = math.radians(angle)
        self.x, self.y = (self.x * math.cos(rad) - self.y * math.sin(rad), self.x * math.sin(rad) + self.y * math.cos(rad))

def transform_sequence(coord, sequence):
    for action in sequence:
        if action[0] == 'translate':
            coord.translate(*action[1:])
        elif action[0] == 'rotate_x':
            coord.rotate_x(action[1])
        elif action[0] == 'rotate_y':
            coord.rotate_y(action[1])
        elif action[0] == 'rotate_z':
            coord.rotate_z(action[1])

def main():
    coord = CoordinateTransform(1, 2, 3)
    sequence = [('translate', 1, 1, 1), ('rotate_x', 45), ('rotate_y', 45), ('rotate_z', 45), ('translate', -1, -1, -1)]
    while True:
        transform_sequence(coord, sequence)
        print(f'({coord.x}, {coord.y}, {coord.z})')
main()