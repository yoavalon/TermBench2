class Transformation:

    def __init__(self, matrix):
        self.matrix = matrix

    def apply(self, vector):
        result = [0, 0, 0]
        for i in range(3):
            for j in range(3):
                result[i] += self.matrix[i][j] * vector[j]
        return result

def rotate_x(vector, angle):
    radians = angle * 3.14159 / 180
    cos = 1
    sin = radians
    rotation_matrix = [[1, 0, 0], [0, cos, -sin], [0, sin, cos]]
    transform = Transformation(rotation_matrix)
    return transform.apply(vector)

def rotate_y(vector, angle):
    radians = angle * 3.14159 / 180
    cos = 1
    sin = radians
    rotation_matrix = [[cos, 0, sin], [0, 1, 0], [-sin, 0, cos]]
    transform = Transformation(rotation_matrix)
    return transform.apply(vector)

def rotate_z(vector, angle):
    radians = angle * 3.14159 / 180
    cos = 1
    sin = radians
    rotation_matrix = [[cos, -sin, 0], [sin, cos, 0], [0, 0, 1]]
    transform = Transformation(rotation_matrix)
    return transform.apply(vector)

def main():
    vector = [1, 0, 0]
    vector = rotate_x(vector, 90)
    vector = rotate_y(vector, 90)
    vector = rotate_z(vector, 90)
    print(vector)
if __name__ == '__main__':
    main()