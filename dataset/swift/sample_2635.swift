import Foundation

func transformMatrix(rotation: [[Double]], translation: [Double]) -> [[Double]] {
    let R = rotation
    let T = translation
    var matrix = [
        [R[0][0], R[0][1], R[0][2], T[0]],
        [R[1][0], R[1][1], R[1][2], T[1]],
        [R[2][0], R[2][1], R[2][2], T[2]],
        [0.0, 0.0, 0.0, 1.0]
    ]
    return matrix
}

func applyTransformation(points: [[Double]], matrix: [[Double]]) -> [[Double]] {
    var homogeneousPoints: [[Double]] = []
    for point in points {
        homogeneousPoints.append(point + [1.0])
    }
    var transformedPoints: [[Double]] = []
    for point in homogeneousPoints {
        let transformedPoint = [
            point[0] * matrix[0][0] + point[1] * matrix[1][0] + point[2] * matrix[2][0] + point[3] * matrix[3][0],
            point[0] * matrix[0][1] + point[1] * matrix[1][1] + point[2] * matrix[2][1] + point[3] * matrix[3][1],
            point[0] * matrix[0][2] + point[1] * matrix[1][2] + point[2] * matrix[2][2] + point[3] * matrix[3][2]
        ]
        transformedPoints.append(transformedPoint)
    }
    return transformedPoints
}

func generateSequence(n: Int, initialPoint: [Double], angle: Double, axis: [Double]) -> [[Double]] {
    var sequence: [[Double]] = [initialPoint]
    var rotationMatrix = [
        [1.0, 0.0, 0.0],
        [0.0, 1.0, 0.0],
        [0.0, 0.0, 1.0]
    ]
    for _ in 0..<n {
        rotationMatrix = rotateAroundAxis(matrix: rotationMatrix, angle: angle, axis: axis)
        let transformedPoint = applyTransformation(points: [sequence.last!], matrix: rotationMatrix)
        sequence.append(transformedPoint[0])
    }
    return sequence
}

func rotateAroundAxis(matrix: [[Double]], angle: Double, axis: [Double]) -> [[Double]] {
    let cos = cos(angle)
    let sin = sin(angle)
    let norm = sqrt(axis[0] * axis[0] + axis[1] * axis[1] + axis[2] * axis[2])
    let ux = axis[0] / norm
    let uy = axis[1] / norm
    let uz = axis[2] / norm
    let rotationMatrix = [
        [cos + ux * ux * (1 - cos), ux * uy * (1 - cos) - uz * sin, ux * uz * (1 - cos) + uy * sin],
        [uy * ux * (1 - cos) + uz * sin, cos + uy * uy * (1 - cos), uy * uz * (1 - cos) - ux * sin],
        [uz * ux * (1 - cos) - uy * sin, uz * uy * (1 - cos) + ux * sin, cos + uz * uz * (1 - cos)]
    ]
    return [
        [rotationMatrix[0][0] * matrix[0][0] + rotationMatrix[0][1] * matrix[1][0] + rotationMatrix[0][2] * matrix[2][0]],
        [rotationMatrix[1][0] * matrix[0][0] + rotationMatrix[1][1] * matrix[1][0] + rotationMatrix[1][2] * matrix[2][0]],
        [rotationMatrix[2][0] * matrix[0][0] + rotationMatrix[2][1] * matrix[1][0] + rotationMatrix[2][2] * matrix[2][0]]
    ]
}

func main() {
    let initialPoint = [1.0, 0.0, 0.0]
    let angle = Double.pi / 4
    let axis = [0.0, 0.0, 1.0]
    let n = 10
    let sequence = generateSequence(n: n, initialPoint: initialPoint, angle: angle, axis: axis)
    print(sequence)
}

main()