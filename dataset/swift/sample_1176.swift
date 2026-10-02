import Foundation

class Point3D {
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

    func rotate_x(angle: Double) {
        let cos_a = cos(angle)
        let sin_a = sin(angle)
        let y = self.y * cos_a - self.z * sin_a
        let z = self.y * sin_a + self.z * cos_a
        self.y = y
        self.z = z
    }

    func rotate_y(angle: Double) {
        let cos_a = cos(angle)
        let sin_a = sin(angle)
        let x = self.x * cos_a + self.z * sin_a
        let z = -self.x * sin_a + self.z * cos_a
        self.x = x
        self.z = z
    }

    func rotate_z(angle: Double) {
        let cos_a = cos(angle)
        let sin_a = sin(angle)
        let x = self.x * cos_a - self.y * sin_a
        let y = self.x * sin_a + self.y * cos_a
        self.x = x
        self.y = y
    }
}

func transform_point(point: Point3D, angles: [Double], translations: [Double]) {
    point.rotate_x(angle: angles[0])
    point.rotate_y(angle: angles[1])
    point.rotate_z(angle: angles[2])
    point.translate(dx: translations[0], dy: translations[1], dz: translations[2])
}

func recursive_transform(point: Point3D, angles: [Double], translations: [Double]) {
    transform_point(point: point, angles: angles, translations: translations)
    recursive_transform(point: point, angles: angles, translations: translations)
}

func main() {
    let p = Point3D(x: 1, y: 0, z: 0)
    let a = [0.1, 0.2, 0.3]
    let t = [0.1, 0.1, 0.1]
    recursive_transform(point: p, angles: a, translations: t)
}

main()