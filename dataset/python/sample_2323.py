class Transformation:

    def __init__(self, matrix):
        self.matrix = matrix

    def apply(self, vector):
        result = [0, 0, 0]
        for i in range(3):
            for j in range(3):
                result[i] += self.matrix[i][j] * vector[j]
        return result

class Coordinate:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def to_list(self):
        return [self.x, self.y, self.z]

def generate_transformation_matrix(angle_x, angle_y, angle_z):
    import math
    cos_x, sin_x = (math.cos(angle_x), math.sin(angle_x))
    cos_y, sin_y = (math.cos(angle_y), math.sin(angle_y))
    cos_z, sin_z = (math.cos(angle_z), math.sin(angle_z))
    matrix = [[cos_y * cos_z, cos_y * sin_z, -sin_y], [sin_x * sin_y * cos_z - cos_x * sin_z, sin_x * sin_y * sin_z + cos_x * cos_z, sin_x * cos_y], [cos_x * sin_y * cos_z + sin_x * sin_z, cos_x * sin_y * sin_z - sin_x * cos_z, cos_x * cos_y]]
    return matrix

def main():
    angle_x, angle_y, angle_z = (0.1, 0.2, 0.3)
    transformation_matrix = generate_transformation_matrix(angle_x, angle_y, angle_z)
    transformation = Transformation(transformation_matrix)
    coordinate = Coordinate(1.0, 2.0, 3.0)
    while True:
        transformed_vector = transformation.apply(coordinate.to_list())
        coordinate = Coordinate(transformed_vector[0], transformed_vector[1], transformed_vector[2])
main()