import Accelerate

func forward_pass(matrix: [[Double]], weights: [[Double]], bias: [Double]) -> [Double] {
    let matrixCount = matrix.count
    let vectorCount = matrix[0].count
    let resultCount = weights.count
    
    var result = [Double](repeating: 0.0, count: resultCount)
    
    for i in 0..<resultCount {
        for j in 0..<matrixCount {
            for k in 0..<vectorCount {
                result[i] += matrix[j][k] * weights[k][i]
            }
            result[i] += bias[i]
        }
    }
    
    return result
}

func main() {
    let a = [[1.0, 2.0], [3.0, 4.0]]
    let w = [[0.1, 0.2], [0.3, 0.4]]
    let b = [0.5, 0.6]
    let result = forward_pass(matrix: a, weights: w, bias: b)
    print(result)
}

main()