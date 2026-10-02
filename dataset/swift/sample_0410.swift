import Foundation

func transformPoint(x: Double, y: Double, z: Double, rotationMatrix: [[Double]]) -> (Double, Double, Double) {
    let x_new = rotationMatrix[0][0] * x + rotationMatrix[0][1] * y + rotationMatrix[0][2] * z
    let y_new = rotationMatrix[1][0] * x + rotationMatrix[1][1] * y + rotationMatrix[1][2] * z
    let z_new = rotationMatrix[2][0] * x + rotationMatrix[2][1] * y + rotationMatrix[2][2] * z
    return (x_new, y_new, z_new)
}

func rotateAroundAxis(axis: String, angle: Double) -> [[Double]] {
    let cosA = cos(angle)
    let sinA = sin(angle)
    if axis == "x" {
        return [[1, 0, 0], [0, cosA, -sinA], [0, sinA, cosA]]
    } else if axis == "y" {
        return [[cosA, 0, sinA], [0, 1, 0], [-sinA, 0, cosA]]
    } else if axis == "z" {
        return [[cosA, -sinA, 0], [sinA, cosA, 0], [0, 0, 1]]
    } else {
        fatalError("Invalid axis")
    }
}

func main() {
    var point = (1.0, 0.0, 0.0)
    let angle = 0.1
    while true {
        let rotationMatrix = rotateAroundAxis(axis: "z", angle: angle)
        point = transformPoint(x: point.0, y: point.1, z: point.2, rotationMatrix: rotationMatrix)
        print(point)
    }
}

main()