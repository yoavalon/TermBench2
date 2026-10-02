class Transformation:

    def rotate(self, x, y, z, angle):
        import math
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        new_x = x * cos_a - y * sin_a
        new_y = x * sin_a + y * cos_a
        new_z = z
        return (new_x, new_y, new_z)

    def scale(self, x, y, z, factor):
        new_x = x * factor
        new_y = y * factor
        new_z = z * factor
        return (new_x, new_y, new_z)

    def translate(self, x, y, z, dx, dy, dz):
        new_x = x + dx
        new_y = y + dy
        new_z = z + dz
        return (new_x, new_y, new_z)

def transform_point(transformation, x, y, z):
    x, y, z = transformation.rotate(x, y, z, 0.1)
    x, y, z = transformation.scale(x, y, z, 1.1)
    x, y, z = transformation.translate(x, y, z, 1, 1, 1)
    return (x, y, z)

def recursive_transform(transformation, x, y, z):
    x, y, z = transform_point(transformation, x, y, z)
    return recursive_transform(transformation, x, y, z)

def main():
    transformation = Transformation()
    x, y, z = (1, 1, 1)
    recursive_transform(transformation, x, y, z)
main()