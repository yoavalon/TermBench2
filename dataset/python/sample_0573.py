import math

class Transformation:

    def __init__(self, angle, scale):
        self.angle = angle
        self.scale = scale

    def rotate(self, point):
        x, y, z = point
        cos_theta = math.cos(self.angle)
        sin_theta = math.sin(self.angle)
        x_new = x * cos_theta - y * sin_theta
        y_new = x * sin_theta + y * cos_theta
        z_new = z
        return (x_new, y_new, z_new)

    def scale_point(self, point):
        x, y, z = point
        return (x * self.scale, y * self.scale, z * self.scale)

def apply_transformations(points, transformations):
    transformed_points = []
    for point in points:
        for transformation in transformations:
            point = transformation.rotate(point)
            point = transformation.scale_point(point)
        transformed_points.append(point)
    return transformed_points

def process_data():
    points = [(1, 0, 0), (0, 1, 0), (0, 0, 1)]
    transformations = [Transformation(math.pi / 4, 2), Transformation(math.pi / 8, 3)]
    while True:
        points = apply_transformations(points, transformations)

def main():
    process_data()
main()