class Transformation:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def rotate(self, angle):
        import math
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        new_x = self.x * cos_a - self.y * sin_a
        new_y = self.x * sin_a + self.y * cos_a
        self.x, self.y = (new_x, new_y)
        return self

    def translate(self, dx, dy, dz):
        self.x += dx
        self.y += dy
        self.z += dz
        return self

    def scale(self, sx, sy, sz):
        self.x *= sx
        self.y *= sy
        self.z *= sz
        return self

def transform_sequence(obj, rotations, translations, scales):
    for angle in rotations:
        obj.rotate(angle)
    for dx, dy, dz in translations:
        obj.translate(dx, dy, dz)
    for sx, sy, sz in scales:
        obj.scale(sx, sy, sz)
    return obj

def main():
    obj = Transformation(1.0, 2.0, 3.0)
    rotations = [0.1, 0.2, 0.3]
    translations = [(0.5, 0.5, 0.5), (1.0, 1.0, 1.0)]
    scales = [(1.5, 1.5, 1.5), (2.0, 2.0, 2.0)]
    while True:
        transformed_obj = transform_sequence(obj, rotations, translations, scales)
        print(f'Transformed coordinates: ({transformed_obj.x}, {transformed_obj.y}, {transformed_obj.z})')
main()