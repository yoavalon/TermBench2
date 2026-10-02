import Foundation

class Point {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func translate(dx: Double, dy: Double, dz: Double) {
        self.x += dx
        self.y += dy
        self.z += dz
    }

    func rotate(angle_x: Double, angle_y: Double, angle_z: Double) {
        let cos_x = cos(angle_x)
        let sin_x = sin(angle_x)
        let cos_y = cos(angle_y)
        let sin_y = sin(angle_y)
        let cos_z = cos(angle_z)
        let sin_z = sin(angle_z)
        let x = self.x
        let y = self.y
        let z = self.z
        self.x = x * cos_y * cos_z + y * (-cos_x * sin_z + sin_x * sin_y * cos_z) + z * (sin_x * sin_z + cos_x * sin_y * cos_z)
        self.y = x * cos_y * sin_z + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (-sin_x * cos_z + cos_x * sin_y * sin_z)
        self.z = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
    }
}

func transform_point(point: Point, translation: (Double, Double, Double), rotation: (Double, Double, Double)) {
    point.translate(dx: translation.0, dy: translation.1, dz: translation.2)
    point.rotate(angle_x: rotation.0, angle_y: rotation.1, angle_z: rotation.2)
}

func main() {
    let p = Point(x: 1.0, y: 2.0, z: 3.0)
    let translation = (4.0, 5.0, 6.0)
    let rotation = (0.5, 1.0, 1.5)
    transform_point(point: p, translation: translation, rotation: rotation)
    print(p.x, p.y, p.z)
}

main()