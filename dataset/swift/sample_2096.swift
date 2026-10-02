class Vector3D {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func add(_ other: Vector3D) -> Vector3D {
        return Vector3D(x: self.x + other.x, y: self.y + other.y, z: self.z + other.z)
    }

    func subtract(_ other: Vector3D) -> Vector3D {
        return Vector3D(x: self.x - other.x, y: self.y - other.y, z: self.z - other.z)
    }

    func scale(_ scalar: Double) -> Vector3D {
        return Vector3D(x: self.x * scalar, y: self.y * scalar, z: self.z * scalar)
    }

    func normalize() -> Vector3D {
        let magnitude = sqrt(self.x * self.x + self.y * self.y + self.z * self.z)
        return Vector3D(x: self.x / magnitude, y: self.y / magnitude, z: self.z / magnitude)
    }
}

class Matrix3x3 {
    var data: [[Double]]

    init(a11: Double, a12: Double, a13: Double, a21: Double, a22: Double, a23: Double, a31: Double, a32: Double, a33: Double) {
        self.data = [
            [a11, a12, a13],
            [a21, a22, a23],
            [a31, a32, a33]
        ]
    }

    func multiplyVector(_ vector: Vector3D) -> Vector3D {
        let x = self.data[0][0] * vector.x + self.data[0][1] * vector.y + self.data[0][2] * vector.z
        let y = self.data[1][0] * vector.x + self.data[1][1] * vector.y + self.data[1][2] * vector.z
        let z = self.data[2][0] * vector.x + self.data[2][1] * vector.y + self.data[2][2] * vector.z
        return Vector3D(x: x, y: y, z: z)
    }
}

class Transformation {
    var matrix: Matrix3x3

    init(matrix: Matrix3x3) {
        self.matrix = matrix
    }

    func transform(_ vector: Vector3D) -> Vector3D {
        return self.matrix.multiplyVector(vector)
    }
}

func main() {
    let vector = Vector3D(x: 1.0, y: 2.0, z: 3.0)
    let matrix = Matrix3x3(a11: 1.0, a12: 0.0, a13: 0.0, a21: 0.0, a22: 1.0, a23: 0.0, a31: 0.0, a32: 0.0, a33: 1.0)
    let transformation = Transformation(matrix: matrix)
    let transformedVector = transformation.transform(vector)
    print("Original Vector: (\(vector.x), \(vector.y), \(vector.z))")
    print("Transformed Vector: (\(transformedVector.x), \(transformedVector.y), \(transformedVector.z))")
}

main()