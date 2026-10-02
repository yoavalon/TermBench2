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

    func distance(to other: Point3D) -> Double {
        return sqrt(pow(self.x - other.x, 2) + pow(self.y - other.y, 2) + pow(self.z - other.z, 2))
    }

    func rotate(angleX: Double, angleY: Double, angleZ: Double) {
        let cosX = cos(angleX)
        let sinX = sin(angleX)
        let cosY = cos(angleY)
        let sinY = sin(angleY)
        let cosZ = cos(angleZ)
        let sinZ = sin(angleZ)
        let x = self.x
        let y = self.y
        let z = self.z
        self.x = x * cosY * cosZ + y * (sinX * sinY * cosZ - cosX * sinZ) + z * (cosX * sinY * cosZ + sinX * sinZ)
        self.y = x * cosY * sinZ + y * (sinX * sinY * sinZ + cosX * cosZ) + z * (cosX * sinY * sinZ - sinX * cosZ)
        self.z = -x * sinY + y * sinX * cosY + z * cosX * cosY
    }
}

class Transformation {
    var angleX: Double
    var angleY: Double
    var angleZ: Double

    init(angleX: Double, angleY: Double, angleZ: Double) {
        self.angleX = angleX
        self.angleY = angleY
        self.angleZ = angleZ
    }

    func apply(to point: Point3D) {
        point.rotate(angleX: angleX, angleY: angleY, angleZ: angleZ)
    }
}

func simulateTransformation() {
    let point = Point3D(x: 1.0, y: 1.0, z: 1.0)
    let transformation = Transformation(angleX: Double.pi / 4, angleY: Double.pi / 4, angleZ: Double.pi / 4)
    while true {
        transformation.apply(to: point)
        print("(\(String(format: "%.10f", point.x)), \(String(format: "%.10f", point.y)), \(String(format: "%.10f", point.z)))")
    }
}

simulateTransformation()