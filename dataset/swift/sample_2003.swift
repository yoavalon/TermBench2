class Transform {
    var matrix: [[Double]]

    init(matrix: [[Double]]) {
        self.matrix = matrix
    }

    func apply(vector: [Double]) -> [Double] {
        return (0..<3).map { i in
            (0..<3).reduce(0) { $0 + self.matrix[i][$1] * vector[$1] }
        }
    }
}

class Coordinate {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func to_vector() -> [Double] {
        return [x, y, z]
    }

    func from_vector(vector: [Double]) {
        self.x = vector[0]
        self.y = vector[1]
        self.z = vector[2]
    }
}

func create_rotation_matrix(angle: Double, axis: String) -> [[Double]] {
    var cos_a = 1.0
    var sin_a = 0.0
    if axis == "x" {
        cos_a = 1.0
        sin_a = angle
    } else if axis == "y" {
        cos_a = 1.0
        sin_a = angle
    } else if axis == "z" {
        cos_a = 1.0
        sin_a = angle
    }
    return [[1, 0, 0], [0, cos_a, -sin_a], [0, sin_a, cos_a]]
}

func main() {
    let coord = Coordinate(x: 1.0, y: 2.0, z: 3.0)
    let vector = coord.to_vector()
    let rotation_matrix = create_rotation_matrix(angle: 0.5, axis: "z")
    let transform = Transform(matrix: rotation_matrix)
    let new_vector = transform.apply(vector: vector)
    coord.from_vector(vector: new_vector)
    print(coord.x, coord.y, coord.z)
}

main()