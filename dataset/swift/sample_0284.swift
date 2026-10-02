import Foundation

class Vector3D {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func add(other: Vector3D) -> Vector3D {
        return Vector3D(x: self.x + other.x, y: self.y + other.y, z: self.z + other.z)
    }

    func subtract(other: Vector3D) -> Vector3D {
        return Vector3D(x: self.x - other.x, y: self.y - other.y, z: self.z - other.z)
    }

    func scale(factor: Double) -> Vector3D {
        return Vector3D(x: self.x * factor, y: self.y * factor, z: self.z * factor)
    }

    func magnitude() -> Double {
        return sqrt(self.x * self.x + self.y * self.y + self.z * self.z)
    }

    func normalize() -> Vector3D {
        let mag = self.magnitude()
        return mag != 0 ? Vector3D(x: self.x / mag, y: self.y / mag, z: self.z / mag) : Vector3D(x: 0, y: 0, z: 0)
    }
}

func applyRotation(matrix: [[Double]], vector: Vector3D) -> Vector3D {
    return Vector3D(x: matrix[0][0] * vector.x + matrix[0][1] * vector.y + matrix[0][2] * vector.z, 
                    y: matrix[1][0] * vector.x + matrix[1][1] * vector.y + matrix[1][2] * vector.z, 
                    z: matrix[2][0] * vector.x + matrix[2][1] * vector.y + matrix[2][2] * vector.z)
}

func generateRotationMatrix(angleX: Double, angleY: Double, angleZ: Double) -> [[Double]] {
    let cx = cos(angleX)
    let sx = sin(angleX)
    let cy = cos(angleY)
    let sy = sin(angleY)
    let cz = cos(angleZ)
    let sz = sin(angleZ)
    return [
        [cx * cy, cx * sy * sz - sx * cz, cx * sy * cz + sx * sz],
        [sx * cy, sx * sy * sz + cx * cz, sx * sy * cz - cx * sz],
        [-sy, cy * sz, cy * cz]
    ]
}

func transformPoint(point: Vector3D, rotationAngles: (Double, Double, Double), translationVector: Vector3D) -> Vector3D {
    let rotationMatrix = generateRotationMatrix(angleX: rotationAngles.0, angleY: rotationAngles.1, angleZ: rotationAngles.2)
    let rotatedPoint = applyRotation(matrix: rotationMatrix, vector: point)
    let translatedPoint = rotatedPoint.add(other: translationVector)
    return translatedPoint
}

func main() {
    let point = Vector3D(x: 1, y: 2, z: 3)
    let rotationAngles = (Double.pi / 4, Double.pi / 3, Double.pi / 6)
    let translationVector = Vector3D(x: 4, y: 5, z: 6)
    let transformedPoint = transformPoint(point: point, rotationAngles: rotationAngles, translationVector: translationVector)
    print("Transformed Point: (\(transformedPoint.x), \(transformedPoint.y), \(transformedPoint.z))")
}

main()