class TransformationMatrix {
    var a: Double
    var b: Double
    var c: Double
    var d: Double
    var e: Double
    var f: Double
    var g: Double
    var h: Double
    var i: Double

    init(a: Double, b: Double, c: Double, d: Double, e: Double, f: Double, g: Double, h: Double, i: Double) {
        self.a = a
        self.b = b
        self.c = c
        self.d = d
        self.e = e
        self.f = f
        self.g = g
        self.h = h
        self.i = i
    }

    func apply(x: Double, y: Double, z: Double) -> (Double, Double, Double) {
        let newX = a * x + b * y + c * z
        let newY = d * x + e * y + f * z
        let newZ = g * x + h * y + i * z
        return (newX, newY, newZ)
    }
}

class CoordinateTransformer {
    var matrix: TransformationMatrix

    init(matrix: TransformationMatrix) {
        self.matrix = matrix
    }

    func transformPoint(point: (Double, Double, Double)) -> (Double, Double, Double) {
        let (x, y, z) = point
        return matrix.apply(x: x, y: y, z: z)
    }

    func transformPoints(points: [(Double, Double, Double)]) -> [(Double, Double, Double)] {
        return points.map { transformPoint(point: $0) }
    }
}

class GeometryAnalysis {
    var transformer: CoordinateTransformer

    init(transformer: CoordinateTransformer) {
        self.transformer = transformer
    }

    func analyze(points: [(Double, Double, Double)]) -> [Double] {
        let transformedPoints = transformer.transformPoints(points: points)
        var results: [Double] = []
        for point in transformedPoints {
            results.append(calculateDistance(point: point))
        }
        return results
    }

    func calculateDistance(point: (Double, Double, Double)) -> Double {
        let (x, y, z) = point
        return sqrt(x * x + y * y + z * z)
    }
}

func main() {
    let matrix = TransformationMatrix(a: 1.0, b: 0.0, c: 0.0, d: 0.0, e: 1.0, f: 0.0, g: 0.0, h: 0.0, i: 1.0)
    let transformer = CoordinateTransformer(matrix: matrix)
    let analysis = GeometryAnalysis(transformer: transformer)
    let points: [(Double, Double, Double)] = [(1.0, 2.0, 3.0), (4.0, 5.0, 6.0), (7.0, 8.0, 9.0)]
    let results = analysis.analyze(points: points)
    print(results)
}

main()