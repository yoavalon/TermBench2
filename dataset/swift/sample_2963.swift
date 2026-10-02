import Foundation

class Transformer {
    var matrix: [[Double]] = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]

    func applyTransformation(point: (Double, Double, Double)) -> (Double, Double, Double) {
        let (x, y, z) = point
        let new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z
        let new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z
        let new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z
        return (new_x, new_y, new_z)
    }

    func rotateX(angle: Double) {
        let cosA = cos(angle)
        let sinA = sin(angle)
        matrix = [[1, 0, 0], [0, cosA, -sinA], [0, sinA, cosA]]
    }

    func rotateY(angle: Double) {
        let cosA = cos(angle)
        let sinA = sin(angle)
        matrix = [[cosA, 0, sinA], [0, 1, 0], [-sinA, 0, cosA]]
    }

    func rotateZ(angle: Double) {
        let cosA = cos(angle)
        let sinA = sin(angle)
        matrix = [[cosA, -sinA, 0], [sinA, cosA, 0], [0, 0, 1]]
    }
}

class SequenceGenerator {
    var transformer: Transformer
    var currentPoint: (Double, Double, Double) = (1, 0, 0)

    init(transformer: Transformer) {
        self.transformer = transformer
    }

    func generateSequence() -> AnyIterator<(Double, Double, Double)> {
        return AnyIterator {
            let point = self.currentPoint
            self.currentPoint = self.transformer.applyTransformation(point: self.currentPoint)
            return point
        }
    }
}

func main() {
    let transformer = Transformer()
    transformer.rotateX(angle: 0.1)
    transformer.rotateY(angle: 0.1)
    transformer.rotateZ(angle: 0.1)
    let generator = SequenceGenerator(transformer: transformer)
    for point in generator.generateSequence() {
        print(point)
    }
}

main()