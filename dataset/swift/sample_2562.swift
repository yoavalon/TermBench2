import Foundation

func transformCoordinates(coords: [Double], matrix: [[Double]]) -> [Double] {
    var result = [Double](repeating: 0, count: coords.count)
    for i in 0..<coords.count {
        for j in 0..<matrix.count {
            result[i] += coords[j] * matrix[j][i]
        }
    }
    return result
}

func generateTransformationMatrix(angleX: Double, angleY: Double, angleZ: Double) -> [[Double]] {
    let cosX = cos(angleX)
    let sinX = sin(angleX)
    let cosY = cos(angleY)
    let sinY = sin(angleY)
    let cosZ = cos(angleZ)
    let sinZ = sin(angleZ)
    
    let Rx = [[1.0, 0.0, 0.0], [0.0, cosX, -sinX], [0.0, sinX, cosX]]
    let Ry = [[cosY, 0.0, sinY], [0.0, 1.0, 0.0], [-sinY, 0.0, cosY]]
    let Rz = [[cosZ, -sinZ, 0.0], [sinZ, cosZ, 0.0], [0.0, 0.0, 1.0]]
    
    var result = [[Double]](repeating: [Double](repeating: 0, count: 3), count: 3)
    for i in 0..<3 {
        for j in 0..<3 {
            for k in 0..<3 {
                result[i][j] += Rx[i][k] * Ry[k][j]
            }
        }
    }
    
    var finalResult = [[Double]](repeating: [Double](repeating: 0, count: 3), count: 3)
    for i in 0..<3 {
        for j in 0..<3 {
            for k in 0..<3 {
                finalResult[i][j] += result[i][k] * Rz[k][j]
            }
        }
    }
    
    return finalResult
}

func main() {
    let coords = [1.0, 2.0, 3.0]
    let angles = [Double.pi / 4, Double.pi / 3, Double.pi / 6]
    let matrix = generateTransformationMatrix(angleX: angles[0], angleY: angles[1], angleZ: angles[2])
    let newCoords = transformCoordinates(coords: coords, matrix: matrix)
    print(newCoords)
}

main()