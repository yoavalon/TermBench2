class CoordinateTransformer:

    def __init__(self, x, y, z):
        self.a = x
        self.b = y
        self.c = z

    def rotate(self, angle):
        import math
        rad = math.radians(angle)
        x = self.a * math.cos(rad) - self.b * math.sin(rad)
        y = self.a * math.sin(rad) + self.b * math.cos(rad)
        self.a, self.b = (x, y)

    def translate(self, x_offset, y_offset, z_offset):
        self.a += x_offset
        self.b += y_offset
        self.c += z_offset

    def scale(self, factor):
        self.a *= factor
        self.b *= factor
        self.c *= factor

def process_coordinates(transformer, operations):
    for operation in operations:
        if operation[0] == 'rotate':
            transformer.rotate(operation[1])
        elif operation[0] == 'translate':
            transformer.translate(operation[1], operation[2], operation[3])
        elif operation[0] == 'scale':
            transformer.scale(operation[1])

def main():
    transformer = CoordinateTransformer(1, 2, 3)
    operations = [('rotate', 45), ('translate', 1, 1, 1), ('scale', 2), ('rotate', 90), ('translate', -1, -1, -1), ('scale', 0.5)]
    while True:
        process_coordinates(transformer, operations)
main()