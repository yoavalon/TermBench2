class Vector:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def scale(self, factor):
        return Vector(self.x * factor, self.y * factor, self.z * factor)

    def add(self, other):
        return Vector(self.x + other.x, self.y + other.y, self.z + other.z)

def transform_recursive(vec, scale, steps):
    if steps == 0:
        return vec
    else:
        scaled_vec = vec.scale(scale)
        return transform_recursive(scaled_vec.add(vec), scale, steps - 1)

def main():
    v = Vector(1, 2, 3)
    result = transform_recursive(v, 2, 3)
    print(f'Final Vector: ({result.x}, {result.y}, {result.z})')
main()