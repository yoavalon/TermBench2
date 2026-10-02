import Foundation
import Accelerate

func transformCoordinates(coords: [[Double]], matrix: [[Double]]) -> [[Double]] {
    var result = [[Double]](repeating: [Double](repeating: 0.0, count: 3), count: 3)
    var coordsMatrix = matrixByColumnMajor(from: coords)
    var matrixMatrix = matrixByColumnMajor(from: matrix)
    var resultMatrix = matrixByColumnMajor(from: result)
    
    let m = 3
    let n = 3
    let k = 3
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, n, k, 1.0, &coordsMatrix, k, &matrixMatrix, n, 0.0, &resultMatrix, n)
    
    return matrixByRowMajor(from: resultMatrix)
}

func generateTransformationMatrix(angleX: Double, angleY: Double, angleZ: Double) -> [[Double]] {
    let cX = cos(angleX)
    let sX = sin(angleX)
    let cY = cos(angleY)
    let sY = sin(angleY)
    let cZ = cos(angleZ)
    let sZ = sin(angleZ)
    
    let rotX = [
        [1, 0, 0],
        [0, cX, -sX],
        [0, sX, cX]
    ]
    
    let rotY = [
        [cY, 0, sY],
        [0, 1, 0],
        [-sY, 0, cY]
    ]
    
    let rotZ = [
        [cZ, -sZ, 0],
        [sZ, cZ, 0],
        [0, 0, 1]
    ]
    
    let tempMatrix1 = multiplyMatrices(rotZ, rotY)
    let transformationMatrix = multiplyMatrices(tempMatrix1, rotX)
    
    return transformationMatrix
}

func multiplyMatrices(_ matrix1: [[Double]], _ matrix2: [[Double]]) -> [[Double]] {
    var result = [[Double]](repeating: [Double](repeating: 0.0, count: matrix2[0].count), count: matrix1.count)
    for i in 0..<matrix1.count {
        for j in 0..<matrix2[0].count {
            for k in 0..<matrix2.count {
                result[i][j] += matrix1[i][k] * matrix2[k][j]
            }
        }
    }
    return result
}

func matrixByColumnMajor(from matrix: [[Double]]) -> [Double] {
    var columnMajorMatrix: [Double] = []
    for i in 0..<matrix[0].count {
        for j in 0..<matrix.count {
            columnMajorMatrix.append(matrix[j][i])
        }
    }
    return columnMajorMatrix
}

func matrixByRowMajor(from matrix: [Double]) -> [[Double]] {
    var rowMajorMatrix: [[Double]] = []
    let rows = 3
    let columns = 3
    for i in 0..<rows {
        var row: [Double] = []
        for j in 0..<columns {
            row.append(matrix[i * columns + j])
        }
        rowMajorMatrix.append(row)
    }
    return rowMajorMatrix
}

func main() {
    let initialCoords = [
        [1.0, 0.0, 0.0],
        [0.0, 1.0, 0.0],
        [0.0, 0.0, 1.0]
    ]
    let angles = [45.0, 30.0, 60.0].map { $0 * .pi / 180.0 }
    let transformationMatrix = generateTransformationMatrix(angleX: angles[0], angleY: angles[1], angleZ: angles[2])
    let transformedCoords = transformCoordinates(coords: initialCoords, matrix: transformationMatrix)
    print(transformedCoords)
}

main()