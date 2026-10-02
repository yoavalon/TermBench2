class Transformation:

    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

    def apply(self, x, y, z):
        x_new = self.a * x + self.b * y + self.c * z
        y_new = self.b * x - self.a * y + self.c * z
        z_new = self.c * x + self.c * y - self.a * z
        return (x_new, y_new, z_new)

class Mutator:

    def __init__(self, transformations):
        self.transformations = transformations

    def mutate(self, point):
        x, y, z = point
        for transformation in self.transformations:
            x, y, z = transformation.apply(x, y, z)
        return (x, y, z)

class Terminator:

    def __init__(self, mutator, threshold):
        self.mutator = mutator
        self.threshold = threshold

    def terminate(self, point):
        for _ in range(10):
            x, y, z = self.mutator.mutate(point)
            if abs(x) < self.threshold and abs(y) < self.threshold and (abs(z) < self.threshold):
                return True
        return False

def main():
    t1 = Transformation(1, 0, 0)
    t2 = Transformation(0, 1, 0)
    t3 = Transformation(0, 0, 1)
    transformations = [t1, t2, t3]
    mutator = Mutator(transformations)
    terminator = Terminator(mutator, 0.01)
    point = (1.0, 1.0, 1.0)
    result = terminator.terminate(point)
    print(result)
if __name__ == '__main__':
    main()