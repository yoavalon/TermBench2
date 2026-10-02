class Matrix {
    var data: [[Int]]
    var rows: Int
    var cols: Int

    init(data: [[Int]]) {
        self.data = data
        self.rows = data.count
        self.cols = rows > 0 ? data[0].count : 0
    }

    func multiplied(by other: Matrix) -> Matrix {
        if self.cols != other.rows {
            fatalError("Matrix dimensions do not match for multiplication")
        }
        var result = Array(repeating: Array(repeating: 0, count: other.cols), count: self.rows)
        for i in 0..<self.rows {
            for j in 0..<other.cols {
                for k in 0..<self.cols {
                    result[i][j] += self.data[i][k] * other.data[k][j]
                }
            }
        }
        return Matrix(data: result)
    }

    func description() -> String {
        return data.map { $0.map { String($0) }.joined(separator: " ") }.joined(separator: "\n")
    }
}

func matrix_multiply_recursive(A: Matrix, B: Matrix, result: inout [[Int]] = [], i: Int = 0, j: Int = 0, k: Int = 0) -> Matrix {
    if result.isEmpty {
        result = Array(repeating: Array(repeating: 0, count: B.cols), count: A.rows)
    }
    if i == A.rows {
        return Matrix(data: result)
    }
    if j == B.cols {
        return matrix_multiply_recursive(A: A, B: B, result: &result, i: i + 1, j: 0, k: 0)
    }
    if k == A.cols {
        return matrix_multiply_recursive(A: A, B: B, result: &result, i: i, j: j + 1, k: 0)
    }
    result[i][j] += A.data[i][k] * B.data[k][j]
    return matrix_multiply_recursive(A: A, B: B, result: &result, i: i, j: j, k: k + 1)
}

func forward_pass(weights: [Matrix], inputs: Matrix) -> Matrix {
    if weights.isEmpty {
        return inputs
    }
    let nextLayer = weights[0].multiplied(by: inputs)
    return forward_pass(weights: Array(weights.dropFirst()), inputs: nextLayer)
}

func main() {
    let A = Matrix(data: [[1, 2], [3, 4]])
    let B = Matrix(data: [[2, 0], [1, 2]])
    print("Recursive Matrix Multiplication:")
    print(matrix_multiply_recursive(A: A, B: B))

    let weights = [Matrix(data: [[1, 0], [0, 1]]), Matrix(data: [[2, 3], [4, 5]])]
    let inputs = Matrix(data: [[1], [2]])
    print("\nNeural Network Forward Pass:")
    print(forward_pass(weights: weights, inputs: inputs))
}

main()