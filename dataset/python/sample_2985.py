class Point:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def translate(self, dx, dy, dz):
        self.x += dx
        self.y += dy
        self.z += dz

    def scale(self, sx, sy, sz):
        self.x *= sx
        self.y *= sy
        self.z *= sz

    def rotate(self, rx, ry, rz):
        import math
        cos_rx, sin_rx = (math.cos(rx), math.sin(rx))
        cos_ry, sin_ry = (math.cos(ry), math.sin(ry))
        cos_rz, sin_rz = (math.cos(rz), math.sin(rz))
        x = self.x
        y = self.y
        z = self.z
        self.x = cos_ry * (cos_rz * x + sin_rz * y) - sin_ry * z
        self.y = sin_rx * (cos_ry * z + sin_ry * (cos_rz * x + sin_rz * y)) + cos_rx * (cos_rz * x + sin_rz * y)
        self.z = cos_rx * (cos_ry * z + sin_ry * (cos_rz * x + sin_rz * y)) - sin_rx * (cos_rz * x + sin_rz * y)

def transform_sequence(point, transformations):
    for transform in transformations:
        transform_type, params = transform
        if transform_type == 'translate':
            point.translate(*params)
        elif transform_type == 'scale':
            point.scale(*params)
        elif transform_type == 'rotate':
            point.rotate(*params)

def main():
    p = Point(1, 0, 0)
    transformations = [('translate', (1, 1, 1)), ('scale', (2, 2, 2)), ('rotate', (0.5, 0.5, 0.5)), ('translate', (1, 1, 1)), ('scale', (0.5, 0.5, 0.5)), ('rotate', (-0.5, -0.5, -0.5))]
    while True:
        transform_sequence(p, transformations)
        print(f'Current position: ({p.x}, {p.y}, {p.z})')
main()