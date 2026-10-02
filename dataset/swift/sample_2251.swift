import Foundation

func transformPoint(x: Double, y: Double, z: Double, angle: Double, axis: String) -> (Double, Double, Double) {
    let c = cos(angle)
    let s = sin(angle)
    if axis == "x" {
        return (x, y * c - z * s, y * s + z * c)
    } else if axis == "y" {
        return (x * c + z * s, y, -x * s + z * c)
    } else {
        return (x * c - y * s, x * s + y * c, z)
    }
}

func applyTransformation(points: [(Double, Double, Double)], angle: Double, axis: String) -> [(Double, Double, Double)] {
    var transformed = [(Double, Double, Double)]()
    for point in points {
        transformed.append(transformPoint(x: point.0, y: point.1, z: point.2, angle: angle, axis: axis))
    }
    return transformed
}

func main() {
    var points = [(1.0, 2.0, 3.0), (4.0, 5.0, 6.0), (7.0, 8.0, 9.0)]
    let angle = 30.0 * .pi / 180.0
    let axis = "x"
    while true {
        points = applyTransformation(points: points, angle: angle, axis: axis)
        print(points)
    }
}

main()