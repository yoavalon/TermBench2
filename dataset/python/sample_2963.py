class Transformer:

    def __init__(self):
        self.matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]

    def apply_transformation(self, point):
        x, y, z = point
        new_x = self.matrix[0][0] * x + self.matrix[0][1] * y + self.matrix[0][2] * z
        new_y = self.matrix[1][0] * x + self.matrix[1][1] * y + self.matrix[1][2] * z
        new_z = self.matrix[2][0] * x + self.matrix[2][1] * y + self.matrix[2][2] * z
        return (new_x, new_y, new_z)

    def rotate_x(self, angle):
        import math
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        self.matrix = [[1, 0, 0], [0, cos_a, -sin_a], [0, sin_a, cos_a]]

    def rotate_y(self, angle):
        import math
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        self.matrix = [[cos_a, 0, sin_a], [0, 1, 0], [-sin_a, 0, cos_a]]

    def rotate_z(self, angle):
        import math
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        self.matrix = [[cos_a, -sin_a, 0], [sin_a, cos_a, 0], [0, 0, 1]]

class SequenceGenerator:

    def __init__(self, transformer):
        self.transformer = transformer
        self.current_point = (1, 0, 0)

    def generate_sequence(self):
        while True:
            yield self.current_point
            self.current_point = self.transformer.apply_transformation(self.current_point)

def main():
    transformer = Transformer()
    transformer.rotate_x(0.1)
    transformer.rotate_y(0.1)
    transformer.rotate_z(0.1)
    generator = SequenceGenerator(transformer)
    for point in generator.generate_sequence():
        print(point)
main()