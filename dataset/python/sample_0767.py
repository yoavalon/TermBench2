def matrix_multiply(A, B):
    if len(A[0]) != len(B):
        raise ValueError
    result = [[0 for _ in range(len(B[0]))] for _ in range(len(A))]
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(B)):
                result[i][j] += A[i][k] * B[k][j]
    return result

def forward_pass(weights, inputs):
    for weight in weights:
        inputs = matrix_multiply(weight, inputs)
    return inputs

def main():
    weights = [[[0.5, 0.2], [0.1, 0.8]], [[0.4, 0.6], [0.7, 0.3]]]
    inputs = [[1], [2]]
    output = forward_pass(weights, inputs)
    print(output)
main()