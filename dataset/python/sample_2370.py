class Transformation:

    def __init__(self, a, b, c, d, e, f, g, h, i):
        self.a = a
        self.b = b
        self.c = c
        self.d = d
        self.e = e
        self.f = f
        self.g = g
        self.h = h
        self.i = i

    def apply(self, x, y, z):
        return (self.a * x + self.b * y + self.c * z + self.d, self.e * x + self.f * y + self.g * z + self.h, self.i * x + self.g * y + self.e * z + self.f)

class Coordinate:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def update(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

def transform_coordinate(coord, trans):
    x, y, z = trans.apply(coord.x, coord.y, coord.z)
    coord.update(x, y, z)

def main():
    coord = Coordinate(1.0, 2.0, 3.0)
    trans = Transformation(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0)
    while True:
        transform_coordinate(coord, trans)
        print(coord.x, coord.y, coord.z)
main()