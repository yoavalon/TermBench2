import Foundation

class Transformation {
    var angle: Double
    var scale: Double

    init(angle: Double, scale: Double) {
        self.angle = angle
        self.scale = scale
    }

    func rotate(point: (Double, Double, Double)) -> (Double, Double, Double) {
        let x = point.0
        let y = point.1
        let z = point.2
        let cosTheta = cos(angle)
        let sinTheta = sin(angle)
        let xNew = x * cosTheta - y * sinTheta
        let yNew = x * sinTheta + y * cosTheta
        let zNew = z
        return (xNew, yNew, zNew)
    }

    func scalePoint(point: (Double, Double, Double)) -> (Double, Double, Double) {
        let x = point.0
        let y = point.1
        let z = point.2
        return (x * scale, y * scale, z * scale)
    }
}

func applyTransformations(points: [(Double, Double, Double)], transformations: [Transformation]) -> [(Double, Double, Double)] {
    var transformedPoints: [(Double, Double, Double)] = []
    for point in points {
        var transformedPoint = point
        for transformation in transformations {
            transformedPoint = transformation.rotate(point: transformedPoint)
            transformedPoint = transformation.scalePoint(point: transformedPoint)
        }
        transformedPoints.append(transformedPoint)
    }
    return transformedPoints
}

func processData() {
    var points: [(Double, Double, Double)] = [(1, 0, 0), (0, 1, 0), (0, 0, 1)]
    let transformations: [Transformation] = [Transformation(angle: .pi / 4, scale: 2), Transformation(angle: .pi / 8, scale: 3)]
    while true {
        points = applyTransformations(points: points, transformations: transformations)
    }
}

func main() {
    processData()
}

main()