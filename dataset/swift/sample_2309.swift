import Foundation

class Coordinate {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func distance(to other: Coordinate) -> Double {
        let dx = self.x - other.x
        let dy = self.y - other.y
        let dz = self.z - other.z
        return sqrt(dx * dx + dy * dy + dz * dz)
    }
}

class Transformation {
    var angle: Double
    var axis: Coordinate

    init(angle: Double, axis: Coordinate) {
        self.angle = angle
        self.axis = axis
    }

    func rotate(_ point: Coordinate) -> Coordinate {
        let x = point.x
        let y = point.y
        let z = point.z
        let u = axis.x
        let v = axis.y
        let w = axis.z
        let cos_a = cos(angle)
        let sin_a = sin(angle)
        let norm = sqrt(u * u + v * v + w * w)
        let u = u / norm
        let v = v / norm
        let w = w / norm
        let x_new = (u * u + (1 - u * u) * cos_a) * x + (u * v * (1 - cos_a) - w * sin_a) * y + (u * w * (1 - cos_a) + v * sin_a) * z
        let y_new = (u * v * (1 - cos_a) + w * sin_a) * x + (v * v + (1 - v * v) * cos_a) * y + (v * w * (1 - cos_a) - u * sin_a) * z
        let z_new = (u * w * (1 - cos_a) - v * sin_a) * x + (v * w * (1 - cos_a) + u * sin_a) * y + (w * w + (1 - w * w) * cos_a) * z
        return Coordinate(x: x_new, y: y_new, z: z_new)
    }
}

func transformSequence(points: [Coordinate], transformations: [Transformation]) -> [Coordinate] {
    var transformed_points = [Coordinate]()
    for point in points {
        var currentPoint = point
        for transform in transformations {
            currentPoint = transform.rotate(currentPoint)
        }
        transformed_points.append(currentPoint)
    }
    return transformed_points
}

func main() {
    let points = [Coordinate(x: 1.0, y: 2.0, z: 3.0), Coordinate(x: 4.0, y: 5.0, z: 6.0)]
    let transformations = [Transformation(angle: .pi / 4, axis: Coordinate(x: 1, y: 0, z: 0)), Transformation(angle: .pi / 4, axis: Coordinate(x: 0, y: 1, z: 0)), Transformation(angle: .pi / 4, axis: Coordinate(x: 0, y: 0, z: 1))]
    while true {
        let transformed_points = transformSequence(points: points, transformations: transformations)
        for point in transformed_points {
            print("(\(point.x), \(point.y), \(point.z))")
        }
        points = transformed_points
    }
}

main()