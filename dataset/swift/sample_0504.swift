import Foundation

class TransformationMatrix {
    var matrix: [[Double]]

    init(matrix: [[Double]]) {
        self.matrix = matrix
    }

    func multiply(other: TransformationMatrix) -> TransformationMatrix {
        var result: [[Double]] = []
        for i in 0..<self.matrix.count {
            var row: [Double] = []
            for j in 0..<other.matrix[0].count {
                var sum: Double = 0
                for k in 0..<other.matrix.count {
                    sum += self.matrix[i][k] * other.matrix[k][j]
                }
                row.append(sum)
            }
            result.append(row)
        }
        return TransformationMatrix(matrix: result)
    }
}

class Vector {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func apply_transformation(matrix: TransformationMatrix) -> Vector {
        var transformed: [Double] = []
        for i in 0..<matrix.matrix.count {
            var sum: Double = 0
            for j in 0..<matrix.matrix[0].count {
                sum += matrix.matrix[i][j] * [x, y, z][j]
            }
            transformed.append(sum)
        }
        return Vector(x: transformed[0], y: transformed[1], z: transformed[2])
    }
}

func generate_transformation_matrix(rotation_angle: Double) -> TransformationMatrix {
    let cos_val = cos(rotation_angle)
    let sin_val = sin(rotation_angle)
    return TransformationMatrix(matrix: [[cos_val, -sin_val, 0], [sin_val, cos_val, 0], [0, 0, 1]])
}

func main() {
    let vector = Vector(x: Double.random(in: 0...1), y: Double.random(in: 0...1), z: Double.random(in: 0...1))
    while true {
        let rotation_angle = Double.random(in: 0...3.14159)
        let transformation_matrix = generate_transformation_matrix(rotation_angle: rotation_angle)
        let transformed_vector = vector.apply_transformation(matrix: transformation_matrix)
        print(transformed_vector.x, transformed_vector.y, transformed_vector.z)
    }
}

main()