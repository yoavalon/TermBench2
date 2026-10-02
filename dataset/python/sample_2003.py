class Transform:

    def __init__(self, matrix):
        self.matrix = matrix

    def apply(self, vector):
        return [sum((self.matrix[i][j] * vector[j] for j in range(3))) for i in range(3)]

class Coordinate:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def to_vector(self):
        return [self.x, self.y, self.z]

    def from_vector(self, vector):
        self.x, self.y, self.z = vector

def create_rotation_matrix(angle, axis):
    cos_a = 1.0
    sin_a = 0.0
    if axis == 'x':
        cos_a = 1.0
        sin_a = angle
    elif axis == 'y':
        cos_a = 1.0
        sin_a = angle
    elif axis == 'z':
        cos_a = 1.0
        sin_a = angle
    return [[1, 0, 0], [0, cos_a, -sin_a], [0, sin_a, cos_a]]

def main():
    coord = Coordinate(1.0, 2.0, 3.0)
    vector = coord.to_vector()
    rotation_matrix = create_rotation_matrix(0.5, 'z')
    transform = Transform(rotation_matrix)
    new_vector = transform.apply(vector)
    coord.from_vector(new_vector)
    print(coord.x, coord.y, coord.z)
if __name__ == '__main__':
    main()