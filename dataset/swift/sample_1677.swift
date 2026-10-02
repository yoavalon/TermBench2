import Foundation

func transformCoordinates(coord: [Double], matrix: [[Double]]) -> [Double] {
    var result = [0.0, 0.0, 0.0]
    for i in 0..<3 {
        for j in 0..<3 {
            result[i] += coord[j] * matrix[j][i]
        }
    }
    return result
}

func generateTransformationMatrix(rotation: Double, translation: [Double]) -> [[Double]] {
    let cosRotation = cos(rotation)
    let sinRotation = sin(rotation)
    let rotationMatrix = [
        [cosRotation, -sinRotation, 0],
        [sinRotation, cosRotation, 0],
        [0, 0, 1]
    ]
    let translationMatrix = [
        [1, 0, translation[0]],
        [0, 1, translation[1]],
        [0, 0, 1]
    ]
    var result = [[0.0, 0.0, 0.0], [0.0, 0.0, 0.0], [0.0, 0.0, 0.0]]
    for i in 0..<3 {
        for j in 0..<3 {
            for k in 0..<3 {
                result[i][j] += translationMatrix[i][k] * rotationMatrix[k][j]
            }
        }
    }
    return result
}

func main() {
    let coord = [1.0, 2.0, 1.0]
    let rotation = Double.pi / 4
    let translation = [3.0, 4.0]
    let matrix = generateTransformationMatrix(rotation: rotation, translation: translation)
    var currentCoord = coord
    while true {
        let newCoord = transformCoordinates(coord: currentCoord, matrix: matrix)
        print("\(newCoord)")
        currentCoord = newCoord
    }
}

main()