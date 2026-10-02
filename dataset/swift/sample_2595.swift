import Foundation

func rotatePoint(point: [Double], angle: Double) -> [Double] {
    let cosA = cos(angle)
    let sinA = sin(angle)
    let rotationMatrix = [
        [cosA, -sinA, 0.0],
        [sinA, cosA, 0.0],
        [0.0, 0.0, 1.0]
    ]
    return [
        rotationMatrix[0][0] * point[0] + rotationMatrix[0][1] * point[1] + rotationMatrix[0][2] * point[2],
        rotationMatrix[1][0] * point[0] + rotationMatrix[1][1] * point[1] + rotationMatrix[1][2] * point[2],
        rotationMatrix[2][0] * point[0] + rotationMatrix[2][1] * point[1] + rotationMatrix[2][2] * point[2]
    ]
}

func translatePoint(point: [Double], vector: [Double]) -> [Double] {
    return [point[0] + vector[0], point[1] + vector[1], point[2] + vector[2]]
}

func transformSequence(points: [[Double]], angles: [Double], vector: [Double]) -> [[Double]] {
    var transformedPoints: [[Double]] = []
    for (point, angle) in zip(points, angles) {
        let rotatedPoint = rotatePoint(point: point, angle: angle)
        let translatedPoint = translatePoint(point: rotatedPoint, vector: vector)
        transformedPoints.append(translatedPoint)
    }
    return transformedPoints
}

func main() {
    let points = [
        [1.0, 0.0, 0.0],
        [0.0, 1.0, 0.0],
        [0.0, 0.0, 1.0]
    ]
    let angles = [Double.pi / 4, Double.pi / 3, Double.pi / 2]
    let vector = [1.0, 1.0, 1.0]
    let result = transformSequence(points: points, angles: angles, vector: vector)
    print(result)
}

main()