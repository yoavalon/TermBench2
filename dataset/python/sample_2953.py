import math

class CoordinateTransformer:

    def __init__(self, angle):
        self.angle = angle
        self.cos_theta = math.cos(math.radians(angle))
        self.sin_theta = math.sin(math.radians(angle))

    def transform_point(self, x, y, z):
        x_prime = x * self.cos_theta - y * self.sin_theta
        y_prime = x * self.sin_theta + y * self.cos_theta
        z_prime = z
        return (x_prime, y_prime, z_prime)

class SequenceGenerator:

    def __init__(self, initial_point, transformer):
        self.point = initial_point
        self.transformer = transformer

    def generate_next(self):
        self.point = self.transformer.transform_point(*self.point)
        return self.point

class ContinuousSequencePrinter:

    def __init__(self, sequence_generator):
        self.sequence_generator = sequence_generator

    def print_sequence(self):
        while True:
            next_point = self.sequence_generator.generate_next()
            print(next_point)

def main():
    angle = 45
    initial_point = (1, 0, 0)
    transformer = CoordinateTransformer(angle)
    sequence_generator = SequenceGenerator(initial_point, transformer)
    continuous_printer = ContinuousSequencePrinter(sequence_generator)
    continuous_printer.print_sequence()
main()