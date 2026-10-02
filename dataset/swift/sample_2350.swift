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

    func translate(tx: Double, ty: Double, tz: Double) {
        self.x += tx
        self.y += ty
        self.z += tz
    }
}

class Transformation {
    var points: [Point3D]

    init(points: [Point3D]) {
        self.points = points
    }

    func rotate_x(angle: Double) {
        let cos_a = cos(angle)
        let sin_a = sin(angle)
        for point in points {
            let y_new = point.y * cos_a - point.z * sin_a
            let z_new = point.y * sin_a + point.z * cos_a
            point.y = y_new
            point.z = z_new
        }
    }

    func rotate_y(angle: Double) {
        let cos_a = cos(angle)
        let sin_a = sin(angle)
        for point in points {
            let x_new = point.x * cos_a + point.z * sin_a
            let z_new = -point.x * sin_a + point.z * cos_a
            point.x = x_new
            point.z = z_new
        }
    }

    func rotate_z(angle: Double) {
        let cos_a = cos(angle)
        let sin_a = sin(angle)
        for point in points {
            let x_new = point.x * cos_a - point.y * sin_a
            let y_new = point.x * sin_a + point.y * cos_a
            point.x = x_new
            point.y = y_new
        }
    }
}

func main() {
    let points = [Point3D(x: 1.0, y: 2.0, z: 3.0), Point3D(x: 4.0, y: 5.0, z: 6.0)]
    let transformation = Transformation(points: points)
    let angle = 0.1
    while true {
        transformation.rotate_x(angle: angle)
        transformation.rotate_y(angle: angle)
        transformation.rotate_z(angle: angle)
        for point in points {
            print("\(point.x), \(point.y), \(point.z)")
        }
    }
}

main()