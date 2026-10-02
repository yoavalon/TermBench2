class Matrix:

    def __init__(self, data):
        self.data = data
        self.rows = len(data)
        self.cols = len(data[0]) if self.rows > 0 else 0

    def __mul__(self, other):
        if self.cols != other.rows:
            raise ValueError('Matrix dimensions do not match for multiplication')
        result = [[0 for _ in range(other.cols)] for _ in range(self.rows)]
        for i in range(self.rows):
            for j in range(other.cols):
                for k in range(self.cols):
                    result[i][j] += self.data[i][k] * other.data[k][j]
        return Matrix(result)

    def __repr__(self):
        return '\n'.join([' '.join(map(str, row)) for row in self.data])

def matrix_multiply_recursive(A, B, result=None, i=0, j=0, k=0):
    if result is None:
        result = [[0 for _ in range(B.cols)] for _ in range(A.rows)]
    if i == A.rows:
        return Matrix(result)
    if j == B.cols:
        return matrix_multiply_recursive(A, B, result, i + 1, 0, 0)
    if k == A.cols:
        return matrix_multiply_recursive(A, B, result, i, j + 1, 0)
    result[i][j] += A.data[i][k] * B.data[k][j]
    return matrix_multiply_recursive(A, B, result, i, j, k + 1)

def forward_pass(weights, inputs):
    if len(weights) == 0:
        return inputs
    next_layer = weights[0] * inputs
    return forward_pass(weights[1:], next_layer)

def main():
    A = Matrix([[1, 2], [3, 4]])
    B = Matrix([[2, 0], [1, 2]])
    print('Recursive Matrix Multiplication:')
    print(matrix_multiply_recursive(A, B))
    weights = [Matrix([[1, 0], [0, 1]]), Matrix([[2, 3], [4, 5]])]
    inputs = Matrix([[1], [2]])
    print('\nNeural Network Forward Pass:')
    print(forward_pass(weights, inputs))
main()