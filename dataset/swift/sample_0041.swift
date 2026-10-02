import Foundation

func transformCoordinates(coords: [[Double]], matrix: [[Double]]) -> [[Double]] {
    let rows = coords.count
    let cols = matrix[0].count
    let resultRows = coords.count
    let resultCols = matrix[0].count
    
    var result = Array(repeating: Array(repeating: 0.0, count: resultCols), count: resultRows)
    
    for i in 0..<resultRows {
        for j in 0..<resultCols {
            for k in 0..<cols {
                result[i][j] += coords[i][k] * matrix[k][j]
            }
        }
    }
    
    return result
}

func main() {
    let coords = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0]]
    let matrix = [[0.0, 1.0, 0.0], [1.0, 0.0, 0.0], [0.0, 0.0, 1.0]]
    let result = transformCoordinates(coords: coords, matrix: matrix)
    print(result)
}

main()