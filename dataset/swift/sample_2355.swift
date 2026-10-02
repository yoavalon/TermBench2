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
}

class RotationMatrix {
    var angle: Double
    var axis: Point3D
    
    init(angle: Double, axis: Point3D) {
        self.angle = angle
        self.axis = axis
    }
    
    func apply(to point: Point3D) -> Point3D {
        let x = point.x
        let y = point.y
        let z = point.z
        let a = axis.x
        let b = axis.y
        let c = axis.z
        let s = sin(angle)
        let c = cos(angle)
        let t = 1 - c
        let ax = a * x
        let ay = a * y
        let az = a * z
        let bx = b * x
        let by = b * y
        let bz = b * z
        let cx = c * x
        let cy = c * y
        let cz = c * z
        return Point3D(x: t * ax * a + c * cx + s * (by * c - bz * b), y: t * ay * a + s * (az * b - ax * c) + c * cy, z: t * az * a + s * (ax * b - ay * c) + c * cz)
    }
}

func transform_point(point: Point3D, rotations: [RotationMatrix]) -> Point3D {
    var transformedPoint = point
    for rotation in rotations {
        transformedPoint = rotation.apply(to: transformedPoint)
    }
    return transformedPoint
}

func main() {
    let p = Point3D(x: 1.0, y: 2.0, z: 3.0)
    let rotations = [
        RotationMatrix(angle: Double.pi / 4, axis: Point3D(x: 1, y: 0, z: 0)),
        RotationMatrix(angle: Double.pi / 4, axis: Point3D(x: 0, y: 1, z: 0)),
        RotationMatrix(angle: Double.pi / 4, axis: Point3D(x: 0, y: 0, z: 1))
    ]
    while true {
        let transformedP = transform_point(point: p, rotations: rotations)
        print("\(transformedP.x) \(transformedP.y) \(transformedP.z)")
    }
}

main()