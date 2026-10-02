swift
import Foundation

func transformCoordinates(points: [[Double]], matrix: [[Double]]) -> [[Double]] {
    let rows = points.count
    let cols = matrix[0].count
    let resultRows = points.count
    let resultCols = matrix.count
    
    var result = Array(repeating: Array(repeating: 0.0, count: resultCols), count: resultRows)
    
    for i in 0..<resultRows {
        for j in 0..<resultCols {
            for k in 0..<cols {
                result[i][j] += points[i][k] * matrix[k][j]
            }
        }
    }
    
    return result
}

func main() {
    let points = [
        [1.0, 2.0, 3.0],
        [4.0, 5.0, 6.0],
        [7.0, 8.0, 9.0]
    ]
    
    let matrix = [
        [0.0, 1.0, 0.0],
        [0.0, 0.0, 1.0],
        [1.0, 0.0, 0.0]
    ]
    
    let transformed = transformCoordinates(points: points, matrix: matrix)
    
    for row in transformed {
        print(row)
    }
}

main()