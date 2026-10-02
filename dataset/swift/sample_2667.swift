import Foundation

class Point {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func distance(to other: Point) -> Double {
        return sqrt(pow(self.x - other.x, 2) + pow(self.y - other.y, 2) + pow(self.z - other.z, 2))
    }
}

class Transformation {
    var matrix: [[Double]]

    init(matrix: [[Double]]) {
        self.matrix = matrix
    }

    func apply(to point: Point) -> Point {
        let x = matrix[0][0] * point.x + matrix[0][1] * point.y + matrix[0][2] * point.z + matrix[0][3]
        let y = matrix[1][0] * point.x + matrix[1][1] * point.y + matrix[1][2] * point.z + matrix[1][3]
        let z = matrix[2][0] * point.x + matrix[2][1] * point.y + matrix[2][2] * point.z + matrix[2][3]
        return Point(x: x, y: y, z: z)
    }
}

class Sequence {
    var startPoint: Point
    var transformation: Transformation
    var steps: Int

    init(startPoint: Point, transformation: Transformation, steps: Int) {
        self.startPoint = startPoint
        self.transformation = transformation
        self.steps = steps
    }

    func generate() -> [Point] {
        var points = [startPoint]
        var current = startPoint
        for _ in 0..<steps {
            current = transformation.apply(to: current)
            points.append(current)
        }
        return points
    }
}

func main() {
    let start = Point(x: 0, y: 0, z: 0)
    let matrix = [[1, 0, 0, 1], [0, 1, 0, 1], [0, 0, 1, 1], [0, 0, 0, 1]]
    let transform = Transformation(matrix: matrix)
    let seq = Sequence(startPoint: start, transformation: transform, steps: 10)
    let points = seq.generate()
    let distances = (0..<(points.count - 1)).map { points[$0].distance(to: points[$0 + 1]) }
    print(distances)
}

main()