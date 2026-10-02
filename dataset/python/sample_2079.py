class Point:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def translate(self, dx, dy, dz):
        self.x += dx
        self.y += dy
        self.z += dz

    def rotate(self, angle_x, angle_y, angle_z):
        import math
        cos_x = math.cos(angle_x)
        sin_x = math.sin(angle_x)
        cos_y = math.cos(angle_y)
        sin_y = math.sin(angle_y)
        cos_z = math.cos(angle_z)
        sin_z = math.sin(angle_z)
        x = self.x
        y = self.y
        z = self.z
        self.x = x * cos_y * cos_z + y * (-cos_x * sin_z + sin_x * sin_y * cos_z) + z * (sin_x * sin_z + cos_x * sin_y * cos_z)
        self.y = x * cos_y * sin_z + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (-sin_x * cos_z + cos_x * sin_y * sin_z)
        self.z = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y

def transform_point(point, translation, rotation):
    point.translate(translation[0], translation[1], translation[2])
    point.rotate(rotation[0], rotation[1], rotation[2])

def main():
    p = Point(1.0, 2.0, 3.0)
    translation = (4.0, 5.0, 6.0)
    rotation = (0.5, 1.0, 1.5)
    transform_point(p, translation, rotation)
    print(p.x, p.y, p.z)
if __name__ == '__main__':
    main()