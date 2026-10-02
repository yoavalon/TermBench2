import Foundation

class Vector {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func add(_ other: Vector) -> Vector {
        return Vector(x: self.x + other.x, y: self.y + other.y, z: self.z + other.z)
    }

    func scale(_ factor: Double) -> Vector {
        return Vector(x: self.x * factor, y: self.y * factor, z: self.z * factor)
    }

    override var description: String {
        return "Vector(\(self.x), \(self.y), \(self.z))"
    }
}

class Matrix {
    var a11: Double
    var a12: Double
    var a13: Double
    var a21: Double
    var a22: Double
    var a23: Double
    var a31: Double
    var a32: Double
    var a33: Double

    init(a11: Double, a12: Double, a13: Double, a21: Double, a22: Double, a23: Double, a31: Double, a32: Double, a33: Double) {
        self.a11 = a11
        self.a12 = a12
        self.a13 = a13
        self.a21 = a21
        self.a22 = a22
        self.a23 = a23
        self.a31 = a31
        self.a32 = a32
        self.a33 = a33
    }

    func multiply(_ vector: Vector) -> Vector {
        let x = self.a11 * vector.x + self.a12 * vector.y + self.a13 * vector.z
        let y = self.a21 * vector.x + self.a22 * vector.y + self.a23 * vector.z
        let z = self.a31 * vector.x + self.a32 * vector.y + self.a33 * vector.z
        return Vector(x: x, y: y, z: z)
    }

    override var description: String {
        return "Matrix(\(self.a11), \(self.a12), \(self.a13), \(self.a21), \(self.a22), \(self.a23), \(self.a31), \(self.a32), \(self.a33))"
    }
}

func transform_vector(_ matrix: Matrix, _ vector: Vector, _ depth: Int) -> Vector {
    if depth == 0 {
        return vector
    }
    let transformed = matrix.multiply(vector)
    return transform_vector(matrix, transformed, depth - 1)
}

func main() {
    let vector = Vector(x: 1, y: 2, z: 3)
    let matrix = Matrix(a11: 1, a12: 0, a13: 0, a21: 0, a22: 1, a23: 0, a31: 0, a32: 0, a33: 1)
    let depth = 5
    let result = transform_vector(matrix, vector, depth)
    print(result)
}

main()