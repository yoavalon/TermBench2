import Foundation

class Transform3D {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func rotate_x(angle: Double) {
        let sin_a = sin(angle)
        let cos_a = cos(angle)
        self.y = cos_a * self.y - sin_a * self.z
        self.z = sin_a * self.y + cos_a * self.z
    }

    func rotate_y(angle: Double) {
        let sin_a = sin(angle)
        let cos_a = cos(angle)
        self.x = cos_a * self.x + sin_a * self.z
        self.z = -sin_a * self.x + cos_a * self.z
    }

    func rotate_z(angle: Double) {
        let sin_a = sin(angle)
        let cos_a = cos(angle)
        self.x = cos_a * self.x - sin_a * self.y
        self.y = sin_a * self.x + cos_a * self.y
    }
}

func recursive_transform(coord: inout Transform3D, angle: Double, depth: Int) {
    coord.rotate_x(angle: angle)
    coord.rotate_y(angle: angle)
    coord.rotate_z(angle: angle)
    if depth > 0 {
        recursive_transform(coord: &coord, angle: angle, depth: depth - 1)
    }
}

func main() {
    var coord = Transform3D(x: 1.0, y: 0.0, z: 0.0)
    let angle = Double.pi / 4
    let depth = 1000
    recursive_transform(coord: &coord, angle: angle, depth: depth)
    while true {
        // Infinite loop
    }
}

main()