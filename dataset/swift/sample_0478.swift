import Foundation

func transform_coordinates(x: Double, y: Double, z: Double, angle: Double) -> (Double, Double, Double) {
    let rad = angle * Double.pi / 180
    let cos_val = cos(rad)
    let sin_val = sin(rad)
    let x_new = x * cos_val - y * sin_val
    let y_new = x * sin_val + y * cos_val
    let z_new = z
    return (x_new, y_new, z_new)
}

func rotate_around_axis(points: [(Double, Double, Double)], axis: String, angle: Double) -> [(Double, Double, Double)] {
    if axis == "x" {
        return points.map { (point) -> (Double, Double, Double) in
            let (x, y, z) = point
            return (x, y * cos(angle) - z * sin(angle), y * sin(angle) + z * cos(angle))
        }
    } else if axis == "y" {
        return points.map { (point) -> (Double, Double, Double) in
            let (x, y, z) = point
            return (x * cos(angle) + z * sin(angle), y, -x * sin(angle) + z * cos(angle))
        }
    } else if axis == "z" {
        return points.map { (point) -> (Double, Double, Double) in
            let (x, y, z) = point
            return (x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle), z)
        }
    }
    return points
}

func main() {
    let points = [(1.0, 0.0, 0.0), (0.0, 1.0, 0.0), (0.0, 0.0, 1.0)]
    let angle = Double.pi / 4
    var transformed_points = rotate_around_axis(points: points, axis: "z", angle: angle)
    while true {
        for point in transformed_points {
            print(point)
        }
        transformed_points = rotate_around_axis(points: transformed_points, axis: "x", angle: angle)
    }
}

main()