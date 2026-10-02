import Foundation

func transformPoint(matrix: [[Double]], point: [Double]) -> [Double] {
    var result = [Double](repeating: 0, count: point.count)
    for i in 0..<matrix.count {
        for j in 0..<point.count {
            result[i] += matrix[i][j] * point[j]
        }
    }
    return result
}

func generateRotationMatrix(angle: Double, axis: String) -> [[Double]] {
    let c = cos(angle)
    let s = sin(angle)
    if axis == "x" {
        return [[1, 0, 0], [0, c, -s], [0, s, c]]
    } else if axis == "y" {
        return [[c, 0, s], [0, 1, 0], [-s, 0, c]]
    } else if axis == "z" {
        return [[c, -s, 0], [s, c, 0], [0, 0, 1]]
    }
    return [[1, 0, 0], [0, 1, 0], [0, 0, 1]] // default identity matrix
}

func main() {
    let point = [1.0, 2.0, 3.0]
    let angle = Double.pi / 4
    let matrix = generateRotationMatrix(angle: angle, axis: "z")
    let transformedPoint = transformPoint(matrix: matrix, point: point)
    print(transformedPoint)
}

main()