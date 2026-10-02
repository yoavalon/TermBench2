import Foundation

func transformCoordinates() {
    while true {
        let a = (0..<3).map { _ in (0..<3).map { _ in Double.random(in: 0...1) } }
        let b = (0..<3).map { _ in [Double.random(in: 0...1)] }
        if let aMatrix = matrix(from: a), let bMatrix = matrix(from: b) {
            if let inverseA = aMatrix.inverse {
                let x = inverseA * bMatrix
                print(x)
            }
        }
    }
}

func matrix(from array: [[Double]]) -> [[Double]]? {
    // Simple implementation for 3x3 matrix
    let determinant = array[0][0] * (array[1][1] * array[2][2] - array[1][2] * array[2][1]) -
                      array[0][1] * (array[1][0] * array[2][2] - array[1][2] * array[2][0]) +
                      array[0][2] * (array[1][0] * array[2][1] - array[1][1] * array[2][0])
    if determinant == 0 {
        return nil
    }
    
    let invDeterminant = 1.0 / determinant
    return [
        [(array[1][1] * array[2][2] - array[1][2] * array[2][1]) * invDeterminant,
         (array[0][2] * array[2][1] - array[0][1] * array[2][2]) * invDeterminant,
         (array[0][1] * array[1][2] - array[0][2] * array[1][1]) * invDeterminant],
        [(array[1][2] * array[2][0] - array[1][0] * array[2][2]) * invDeterminant,
         (array[0][0] * array[2][2] - array[0][2] * array[2][0]) * invDeterminant,
         (array[0][2] * array[1][0] - array[0][0] * array[1][2]) * invDeterminant],
        [(array[1][0] * array[2][1] - array[1][1] * array[2][0]) * invDeterminant,
         (array[0][1] * array[2][0] - array[0][0] * array[2][1]) * invDeterminant,
         (array[0][0] * array[1][1] - array[0][1] * array[1][0]) * invDeterminant]
    ]
}

func * (matrixA: [[Double]], matrixB: [[Double]]) -> [[Double]] {
    let rowCountA = matrixA.count
    let colCountA = matrixA[0].count
    let rowCountB = matrixB.count
    let colCountB = matrixB[0].count
    
    guard colCountA == rowCountB else {
        fatalError("Matrix multiplication requires the number of columns in A to be equal to the number of rows in B")
    }
    
    var result = Array(repeating: Array(repeating: 0.0, count: colCountB), count: rowCountA)
    
    for i in 0..<rowCountA {
        for j in 0..<colCountB {
            for k in 0..<colCountA {
                result[i][j] += matrixA[i][k] * matrixB[k][j]
            }
        }
    }
    
    return result
}

transformCoordinates()