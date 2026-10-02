import Foundation

func computeSequence(n: Int) -> [Int] {
    let a = [[1, 2], [3, 4]]
    let b = [[2, 0], [1, 2]]
    var x = [1, 1]
    for _ in 0..<n {
        x = matrixMultiply(a, x) + matrixMultiply(b, x)
    }
    return x
}

func matrixMultiply(_ matrix: [[Int]], _ vector: [Int]) -> [Int] {
    var result = [0, 0]
    for i in 0..<2 {
        for j in 0..<2 {
            result[i] += matrix[i][j] * vector[j]
        }
    }
    return result
}

func + (left: [Int], right: [Int]) -> [Int] {
    return [left[0] + right[0], left[1] + right[1]]
}

computeSequence(n: 5)