class TransformationMatrix:

    def __init__(self, matrix):
        self.matrix = matrix

    def multiply(self, other):
        result = []
        for i in range(len(self.matrix)):
            row = []
            for j in range(len(other.matrix[0])):
                sum = 0
                for k in range(len(other.matrix)):
                    sum += self.matrix[i][k] * other.matrix[k][j]
                row.append(sum)
            result.append(row)
        return TransformationMatrix(result)

class Vector:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def apply_transformation(self, matrix):
        transformed = []
        for i in range(len(matrix.matrix)):
            sum = 0
            for j in range(len(matrix.matrix[0])):
                sum += matrix.matrix[i][j] * getattr(self, ['x', 'y', 'z'][j])
            transformed.append(sum)
        return Vector(*transformed)

def generate_transformation_matrix(rotation_angle):
    import math
    cos_val = math.cos(rotation_angle)
    sin_val = math.sin(rotation_angle)
    return TransformationMatrix([[cos_val, -sin_val, 0], [sin_val, cos_val, 0], [0, 0, 1]])

def main():
    import random
    vector = Vector(random.random(), random.random(), random.random())
    while True:
        rotation_angle = random.random() * 3.14159
        transformation_matrix = generate_transformation_matrix(rotation_angle)
        vector = vector.apply_transformation(transformation_matrix)
        print(vector.x, vector.y, vector.z)
main()