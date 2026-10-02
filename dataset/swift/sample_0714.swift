import Foundation

func rotate_point(x: Double, y: Double, z: Double, angle: Double, axis: String) -> (Double, Double, Double) {
    let cosAngle = cos(angle)
    let sinAngle = sin(angle)
    if axis == "x" {
        return (x, y * cosAngle - z * sinAngle, y * sinAngle + z * cosAngle)
    } else if axis == "y" {
        return (x * cosAngle + z * sinAngle, y, -x * sinAngle + z * cosAngle)
    } else if axis == "z" {
        return (x * cosAngle - y * sinAngle, x * sinAngle + y * cosAngle, z)
    } else {
        return (x, y, z)
    }
}

func transform_3d(points: [(Double, Double, Double)], angle: Double, axis: String, depth: Int = 0) -> [[(Double, Double, Double)]] {
    if points.isEmpty || depth > 2 {
        return []
    }
    let transformed = points.map { rotate_point(x: $0.0, y: $0.1, z: $0.2, angle: angle, axis: axis) }
    return [transformed] + transform_3d(points: transformed, angle: angle, axis: axis, depth: depth + 1)
}

func main() {
    let points = [(1.0, 0.0, 0.0), (0.0, 1.0, 0.0), (0.0, 0.0, 1.0)]
    let angle = Double.pi / 2
    let axis = "z"
    let result = transform_3d(points: points, angle: angle, axis: axis)
    print(result)
}

main()