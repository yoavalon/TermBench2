import Foundation

class Matrix {
    var data: [[Double]]
    var rows: Int
    var cols: Int

    init(_ data: [[Double]]) {
        self.data = data
        self.rows = data.count
        self.cols = rows > 0 ? data[0].count : 0
    }

    func multiplied(by other: Matrix) -> Matrix {
        var result = Array(repeating: Array(repeating: 0.0, count: other.cols), count: self.rows)
        for i in 0..<self.rows {
            for j in 0..<other.cols {
                for k in 0..<other.rows {
                    result[i][j] += self.data[i][k] * other.data[k][j]
                }
            }
        }
        return Matrix(result)
    }

    override var description: String {
        return data.map { $0.map { String(format: "%.2f", $0) }.joined(separator: " ") }.joined(separator: "\n")
    }
}

func rotationMatrix(axis: String, theta: Double) -> Matrix {
    let cosTheta = cos(theta)
    let sinTheta = sin(theta)
    if axis == "x" {
        return Matrix([[1, 0, 0], [0, cosTheta, -sinTheta], [0, sinTheta, cosTheta]])
    } else if axis == "y" {
        return Matrix([[cosTheta, 0, sinTheta], [0, 1, 0], [-sinTheta, 0, cosTheta]])
    } else if axis == "z" {
        return Matrix([[cosTheta, -sinTheta, 0], [sinTheta, cosTheta, 0], [0, 0, 1]])
    }
    return Matrix([[0, 0, 0], [0, 0, 0], [0, 0, 0]])
}

func transformPoint(matrix: Matrix, point: [Double]) -> [Double] {
    let pointMatrix = Matrix([[point[0]], [point[1]], [point[2]]])
    let transformed = matrix.multiplied(by: pointMatrix)
    return [transformed.data[0][0], transformed.data[1][0], transformed.data[2][0]]
}

func main() {
    let point = [1.0, 2.0, 3.0]
    let theta = 0.785398
    let matrixX = rotationMatrix(axis: "x", theta: theta)
    let matrixY = rotationMatrix(axis: "y", theta: theta)
    let matrixZ = rotationMatrix(axis: "z", theta: theta)
    let transformedX = transformPoint(matrix: matrixX, point: point)
    let transformedY = transformPoint(matrix: matrixY, point: point)
    let transformedZ = transformPoint(matrix: matrixZ, point: point)
    print("Transformed by X-axis:", transformedX.map { String(format: "%.2f", $0) }.joined(separator: ", "))
    print("Transformed by Y-axis:", transformedY.map { String(format: "%.2f", $0) }.joined(separator: ", "))
    print("Transformed by Z-axis:", transformedZ.map { String(format: "%.2f", $0) }.joined(separator: ", "))
}

main()