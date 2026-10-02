swift
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

    func dot(other: Vector3D) -> Double {
        return self.x * other.x + self.y * other.y + self.z * other.z
    }

    func magnitude() -> Double {
        return sqrt(self.x * self.x + self.y * self.y + self.z * self.z)
    }

    func normalize() -> Vector3D {
        let mag = self.magnitude()
        return Vector3D(x: self.x / mag, y: self.y / mag, z: self.z / mag)
    }
}

class Matrix3D {
    var data: [[Double]]

    init(a: Double, b: Double, c: Double, d: Double, e: Double, f: Double, g: Double, h: Double, i: Double) {
        self.data = [
            [a, b, c],
            [d, e, f],
            [g, h, i]
        ]
    }

    func multiply(other: Matrix3D) -> Matrix3D {
        var result: [[Double]] = []
        for i in 0..<3 {
            var row: [Double] = []
            for j in 0..<3 {
                var sum: Double = 0
                for k in 0..<3 {
                    sum += self.data[i][k] * other.data[k][j]
                }
                row.append(sum)
            }
            result.append(row)
        }
        return Matrix3D(a: result[0][0], b: result[0][1], c: result[0][2], d: result[1][0], e: result[1][1], f: result[1][2], g: result[2][0], h: result[2][1], i: result[2][2])
    }

    func transform(vector: Vector3D) -> Vector3D {
        let x = self.data[0][0] * vector.x + self.data[0][1] * vector.y + self.data[0][2] * vector.z
        let y = self.data[1][0] * vector.x + self.data[1][1] * vector.y + self.data[1][2] * vector.z
        let z = self.data[2][0] * vector.x + self.data[2][1] * vector.y + self.data[2][2] * vector.z
        return Vector3D(x: x, y: y, z: z)
    }
}

func rotation_matrix(axis: String, theta: Double) -> Matrix3D {
    if axis == "x" {
        return Matrix3D(a: 1, b: 0, c: 0, d: 0, e: cos(theta), f: -sin(theta), g: 0, h: sin(theta), i: cos(theta))
    } else if axis == "y" {
        return Matrix3D(a: cos(theta), b: 0, c: sin(theta), d: 0, e: 1, f: 0, g: -sin(theta), h: 0, i: cos(theta))
    } else if axis == "z" {
        return Matrix3D(a: cos(theta), b: -sin(theta), c: 0, d: sin(theta), e: cos(theta), f: 0, g: 0, h: 0, i: 1)
    } else {
        fatalError("Invalid axis")
    }
}

func main() {
    let v1 = Vector3D(x: 1, y: 2, z: 3)
    let v2 = Vector3D(x: 4, y: 5, z: 6)
    let v3 = v1.add(other: v2)
    let v4 = v2.subtract(other: v1)
    let v5 = v3.scale(factor: 2)
    let dot_product = v1.dot(other: v2)
    let magnitude_v1 = v1.magnitude()
    let normalized_v1 = v1.normalize()
    let rot_x = rotation_matrix(axis: "x", theta: Double.pi / 4)
    let rot_y = rotation_matrix(axis: "y", theta: Double.pi / 4)
    let rot_z = rotation_matrix(axis: "z", theta: Double.pi / 4)
    let v6 = rot_x.transform(vector: v1)
    let v7 = rot_y.transform(vector: v1)
    let v8 = rot_z.transform(vector: v1)
    let matrix_product = rot_x.multiply(other: rot_y)
    print("\(v3.x) \(v3.y) \(v3.z)")
    print("\(v4.x) \(v4.y) \(v4.z)")
    print("\(v5.x) \(v5.y) \(v5.z)")
    print(dot_product)
    print(magnitude_v1)
    print("\(normalized_v1.x) \(normalized_v1.y) \(normalized_v1.z)")
    print("\(v6.x) \(v6.y) \(v6.z)")
    print("\(v7.x) \(v7.y) \(v7.z)")
    print("\(v8.x) \(v8.y) \(v8.z)")
    print(matrix_product.data)
}

main()