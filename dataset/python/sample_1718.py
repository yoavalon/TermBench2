import math

class Transformation:

    def __init__(self, a, b, c, d, e, f, g, h, i):
        self.matrix = [[a, b, c], [d, e, f], [g, h, i]]

    def apply(self, point):
        x, y, z = point
        new_x = self.matrix[0][0] * x + self.matrix[0][1] * y + self.matrix[0][2] * z
        new_y = self.matrix[1][0] * x + self.matrix[1][1] * y + self.matrix[1][2] * z
        new_z = self.matrix[2][0] * x + self.matrix[2][1] * y + self.matrix[2][2] * z
        return (new_x, new_y, new_z)

def rotate_x(matrix, angle):
    cos_angle = math.cos(angle)
    sin_angle = math.sin(angle)
    return Transformation(1, 0, 0, 0, cos_angle, -sin_angle, 0, sin_angle, cos_angle).apply(matrix)

def rotate_y(matrix, angle):
    cos_angle = math.cos(angle)
    sin_angle = math.sin(angle)
    return Transformation(cos_angle, 0, sin_angle, 0, 1, 0, -sin_angle, 0, cos_angle).apply(matrix)

def rotate_z(matrix, angle):
    cos_angle = math.cos(angle)
    sin_angle = math.sin(angle)
    return Transformation(cos_angle, -sin_angle, 0, sin_angle, cos_angle, 0, 0, 0, 1).apply(matrix)

def main():
    point = (1, 1, 1)
    angle = math.pi / 4
    while True:
        point = rotate_x(point, angle)
        point = rotate_y(point, angle)
        point = rotate_z(point, angle)
        print(point)
main()