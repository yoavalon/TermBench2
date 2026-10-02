import Foundation

class Transformation {
    var matrix: [[Double]]

    init(_ a: Double, _ b: Double, _ c: Double, _ d: Double, _ e: Double, _ f: Double, _ g: Double, _ h: Double, _ i: Double) {
        self.matrix = [[a, b, c], [d, e, f], [g, h, i]]
    }

    func apply(_ point: (Double, Double, Double)) -> (Double, Double, Double) {
        let x = point.0, y = point.1, z = point.2
        let new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z
        let new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z
        let new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z
        return (new_x, new_y, new_z)
    }
}

func rotate_x(_ matrix: (Double, Double, Double), _ angle: Double) -> (Double, Double, Double) {
    let cos_angle = cos(angle)
    let sin_angle = sin(angle)
    let transformation = Transformation(1, 0, 0, 0, cos_angle, -sin_angle, 0, sin_angle, cos_angle)
    return transformation.apply(matrix)
}

func rotate_y(_ matrix: (Double, Double, Double), _ angle: Double) -> (Double, Double, Double) {
    let cos_angle = cos(angle)
    let sin_angle = sin(angle)
    let transformation = Transformation(cos_angle, 0, sin_angle, 0, 1, 0, -sin_angle, 0, cos_angle)
    return transformation.apply(matrix)
}

func rotate_z(_ matrix: (Double, Double, Double), _ angle: Double) -> (Double, Double, Double) {
    let cos_angle = cos(angle)
    let sin_angle = sin(angle)
    let transformation = Transformation(cos_angle, -sin_angle, 0, sin_angle, cos_angle, 0, 0, 0, 1)
    return transformation.apply(matrix)
}

func main() {
    var point = (1.0, 1.0, 1.0)
    let angle = Double.pi / 4
    while true {
        point = rotate_x(point, angle)
        point = rotate_y(point, angle)
        point = rotate_z(point, angle)
        print(point)
    }
}

main()