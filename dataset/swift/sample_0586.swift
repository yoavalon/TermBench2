class Transformation {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func rotate(angle: Double) {
        let rad = angle * .pi / 180
        let cos = cos(rad)
        let sin = sin(rad)
        let newX = self.x * cos - self.y * sin
        let newY = self.x * sin + self.y * cos
        self.x = newX
        self.y = newY
    }

    func scale(factor: Double) {
        self.x *= factor
        self.y *= factor
        self.z *= factor
    }

    func translate(dx: Double, dy: Double, dz: Double) {
        self.x += dx
        self.y += dy
        self.z += dz
    }
}

func applyTransformations(obj: inout Transformation, rotations: [Double], scales: [Double], translations: [(Double, Double, Double)]) {
    for angle in rotations {
        obj.rotate(angle: angle)
    }
    for factor in scales {
        obj.scale(factor: factor)
    }
    for (dx, dy, dz) in translations {
        obj.translate(dx: dx, dy: dy, dz: dz)
    }
}

func main() {
    var obj = Transformation(x: 1, y: 2, z: 3)
    let rotations = [45.0, 90.0, 135.0]
    let scales = [2.0, 3.0, 4.0]
    let translations = [(1.0, 0.0, 0.0), (0.0, 1.0, 0.0), (0.0, 0.0, 1.0)]
    applyTransformations(obj: &obj, rotations: rotations, scales: scales, translations: translations)
    while true {
        applyTransformations(obj: &obj, rotations: rotations, scales: scales, translations: translations)
    }
}

main()