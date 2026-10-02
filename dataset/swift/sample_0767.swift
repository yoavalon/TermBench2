func matrix_multiply(_ A: [[Double]], _ B: [[Double]]) -> [[Double]] {
    if A[0].count != B.count {
        fatalError()
    }
    var result = Array(repeating: Array(repeating: 0.0, count: B[0].count), count: A.count)
    for i in 0..<A.count {
        for j in 0..<B[0].count {
            for k in 0..<B.count {
                result[i][j] += A[i][k] * B[k][j]
            }
        }
    }
    return result
}

func forward_pass(_ weights: [[[Double]]], _ inputs: [[Double]]) -> [[Double]] {
    var inputs = inputs
    for weight in weights {
        inputs = matrix_multiply(weight, inputs)
    }
    return inputs
}

func main() {
    let weights = [[[0.5, 0.2], [0.1, 0.8]], [[0.4, 0.6], [0.7, 0.3]]]
    let inputs = [[1.0], [2.0]]
    let output = forward_pass(weights, inputs)
    print(output)
}

main()