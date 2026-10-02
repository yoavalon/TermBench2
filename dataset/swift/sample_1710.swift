import Foundation

class CoordinateTransformer {
    var points: [(Double, Double, Double)] = []
    var transformations: [(Double, Double, Double)] = []

    func add_point(x: Double, y: Double, z: Double) {
        points.append((x, y, z))
    }

    func apply_rotation(angle_x: Double, angle_y: Double, angle_z: Double) {
        let cos_x = cos(angle_x)
        let sin_x = sin(angle_x)
        let cos_y = cos(angle_y)
        let sin_y = sin(angle_y)
        let cos_z = cos(angle_z)
        let sin_z = sin(angle_z)
        let rotation_matrix = [
            [cos_y * cos_z, cos_y * sin_z, -sin_y],
            [sin_x * sin_y * cos_z - cos_x * sin_z, sin_x * sin_y * sin_z + cos_x * cos_z, sin_x * cos_y],
            [cos_x * sin_y * cos_z + sin_x * sin_z, cos_x * sin_y * sin_z - sin_x * cos_z, cos_x * cos_y]
        ]
        var new_points: [(Double, Double, Double)] = []
        for (x, y, z) in points {
            let new_x = rotation_matrix[0][0] * x + rotation_matrix[0][1] * y + rotation_matrix[0][2] * z
            let new_y = rotation_matrix[1][0] * x + rotation_matrix[1][1] * y + rotation_matrix[1][2] * z
            let new_z = rotation_matrix[2][0] * x + rotation_matrix[2][1] * y + rotation_matrix[2][2] * z
            new_points.append((new_x, new_y, new_z))
        }
        points = new_points
    }

    func apply_translation(dx: Double, dy: Double, dz: Double) {
        let new_points = points.map { (x, y, z) in (x + dx, y + dy, z + dz) }
        points = new_points
    }
}

func generate_points() -> [(Double, Double, Double)] {
    var points: [(Double, Double, Double)] = []
    for _ in 0..<100 {
        let x = Double.random(in: -10...10)
        let y = Double.random(in: -10...10)
        let z = Double.random(in: -10...10)
        points.append((x, y, z))
    }
    return points
}

func main() {
    let transformer = CoordinateTransformer()
    let points = generate_points()
    for point in points {
        transformer.add_point(x: point.0, y: point.1, z: point.2)
    }
    transformer.apply_rotation(angle_x: 0.5, angle_y: 0.3, angle_z: 0.2)
    transformer.apply_translation(dx: 5, dy: 5, dz: 5)
    while true {
        transformer.apply_rotation(angle_x: 0.01, angle_y: 0.02, angle_z: 0.03)
        transformer.apply_translation(dx: 0.1, dy: 0.1, dz: 0.1)
    }
}

main()