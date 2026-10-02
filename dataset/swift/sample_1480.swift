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

    func rotate(angleX: Double, angleY: Double, angleZ: Double) {
        let cosX = cos(angleX)
        let sinX = sin(angleX)
        let cosY = cos(angleY)
        let sinY = sin(angleY)
        let cosZ = cos(angleZ)
        let sinZ = sin(angleZ)
        let xNew = self.x * cosY * cosZ + self.y * (sinX * sinY * cosZ - cosX * sinZ) + self.z * (cosX * sinY * cosZ + sinX * sinZ)
        let yNew = self.x * cosY * sinZ + self.y * (sinX * sinY * sinZ + cosX * cosZ) + self.z * (cosX * sinY * sinZ - sinX * cosZ)
        let zNew = self.x * -sinY + self.y * sinX * cosY + self.z * cosX * cosY
        self.x = xNew
        self.y = yNew
        self.z = zNew
    }

    func scale(sx: Double, sy: Double, sz: Double) {
        self.x *= sx
        self.y *= sy
        self.z *= sz
    }
}

func transformPoint(point: Point3D, translations: (Double, Double, Double), rotations: (Double, Double, Double), scales: (Double, Double, Double)) {
    let (dx, dy, dz) = translations
    let (angleX, angleY, angleZ) = rotations
    let (sx, sy, sz) = scales
    point.translate(dx: dx, dy: dy, dz: dz)
    point.rotate(angleX: angleX, angleY: angleY, angleZ: angleZ)
    point.scale(sx: sx, sy: sy, sz: sz)
}

func processPoints(points: [Point3D], transformations: [((Double, Double, Double), (Double, Double, Double), (Double, Double, Double))]) {
    for (point, transformation) in zip(points, transformations) {
        transformPoint(point: point, translations: transformation.0, rotations: transformation.1, scales: transformation.2)
    }
}

func main() {
    let points = [Point3D(x: 1, y: 2, z: 3), Point3D(x: 4, y: 5, z: 6)]
    let transformations = [
        ((1, 1, 1), (0.1, 0.2, 0.3), (1.5, 1.5, 1.5)),
        ((-1, -1, -1), (0.3, 0.2, 0.1), (0.5, 0.5, 0.5))
    ]
    processPoints(points: points, transformations: transformations)
    for point in points {
        print("Point(\(point.x), \(point.y), \(point.z))")
    }
}

main()