class Transformation {
    var matrix: [[Double]]

    init(matrix: [[Double]]) {
        self.matrix = matrix
    }

    func apply(point: (Double, Double, Double)) -> (Double, Double, Double) {
        let (x, y, z) = point
        let newX = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3]
        let newY = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3]
        let newZ = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3]
        return (newX, newY, newZ)
    }
}

class Point {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func transform(matrix: [[Double]]) -> Point {
        let transformed = Transformation(matrix: matrix).apply(point: (self.x, self.y, self.z))
        return Point(x: transformed.0, y: transformed.1, z: transformed.2)
    }
}

func recursiveTransform(point: Point, matrix: [[Double]], depth: Int) -> Point {
    if depth == 0 {
        return point
    } else {
        let newPoint = point.transform(matrix: matrix)
        return recursiveTransform(point: newPoint, matrix: matrix, depth: depth - 1)
    }
}

func main() {
    let matrix = [[1.0, 0.0, 0.0, 1.0], [0.0, 1.0, 0.0, 1.0], [0.0, 0.0, 1.0, 1.0], [0.0, 0.0, 0.0, 1.0]]
    let initialPoint = Point(x: 0.0, y: 0.0, z: 0.0)
    let depth = 5
    let result = recursiveTransform(point: initialPoint, matrix: matrix, depth: depth)
    print("Transformed point: (\(result.x), \(result.y), \(result.z))")
}

main()