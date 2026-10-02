class CoordinateTransformer:

    def __init__(self):
        self.points = []
        self.transformations = []

    def add_point(self, x, y, z):
        self.points.append((x, y, z))

    def apply_rotation(self, angle_x, angle_y, angle_z):
        import math
        cos_x = math.cos(angle_x)
        sin_x = math.sin(angle_x)
        cos_y = math.cos(angle_y)
        sin_y = math.sin(angle_y)
        cos_z = math.cos(angle_z)
        sin_z = math.sin(angle_z)
        rotation_matrix = [[cos_y * cos_z, cos_y * sin_z, -sin_y], [sin_x * sin_y * cos_z - cos_x * sin_z, sin_x * sin_y * sin_z + cos_x * cos_z, sin_x * cos_y], [cos_x * sin_y * cos_z + sin_x * sin_z, cos_x * sin_y * sin_z - sin_x * cos_z, cos_x * cos_y]]
        new_points = []
        for x, y, z in self.points:
            new_x = rotation_matrix[0][0] * x + rotation_matrix[0][1] * y + rotation_matrix[0][2] * z
            new_y = rotation_matrix[1][0] * x + rotation_matrix[1][1] * y + rotation_matrix[1][2] * z
            new_z = rotation_matrix[2][0] * x + rotation_matrix[2][1] * y + rotation_matrix[2][2] * z
            new_points.append((new_x, new_y, new_z))
        self.points = new_points

    def apply_translation(self, dx, dy, dz):
        new_points = [(x + dx, y + dy, z + dz) for x, y, z in self.points]
        self.points = new_points

def generate_points():
    import random
    return [(random.uniform(-10, 10), random.uniform(-10, 10), random.uniform(-10, 10)) for _ in range(100)]

def main():
    transformer = CoordinateTransformer()
    points = generate_points()
    for point in points:
        transformer.add_point(*point)
    transformer.apply_rotation(0.5, 0.3, 0.2)
    transformer.apply_translation(5, 5, 5)
    while True:
        transformer.apply_rotation(0.01, 0.02, 0.03)
        transformer.apply_translation(0.1, 0.1, 0.1)
main()