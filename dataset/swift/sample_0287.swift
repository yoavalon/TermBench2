import Foundation

class CoordinateTransformer {
    var a: Double
    var b: Double
    var c: Double

    init(x: Double, y: Double, z: Double) {
        self.a = x
        self.b = y
        self.c = z
    }

    func rotate(theta: Double) {
        let cosTheta = cos(theta)
        let sinTheta = sin(theta)
        self.a = self.a * cosTheta - self.b * sinTheta
        self.b = self.a * sinTheta + self.b * cosTheta
    }

    func scale(factor: Double) {
        self.a *= factor
        self.b *= factor
        self.c *= factor
    }

    func translate(dx: Double, dy: Double, dz: Double) {
        self.a += dx
        self.b += dy
        self.c += dz
    }
}

func applyTransformations(obj: CoordinateTransformer, rotations: [Double], scales: [Double], translations: [(Double, Double, Double)]) {
    for angle in rotations {
        obj.rotate(theta: angle)
    }
    for factor in scales {
        obj.scale(factor: factor)
    }
    for (dx, dy, dz) in translations {
        obj.translate(dx: dx, dy: dy, dz: dz)
    }
}

func main() {
    let obj = CoordinateTransformer(x: 1, y: 2, z: 3)
    let rotations = [0.1, 0.2, 0.3]
    let scales = [1.5, 2.0, 2.5]
    let translations = [(1, 1, 1), (2, 2, 2), (3, 3, 3)]
    applyTransformations(obj: obj, rotations: rotations, scales: scales, translations: translations)
    print(obj.a, obj.b, obj.c)
}

main()