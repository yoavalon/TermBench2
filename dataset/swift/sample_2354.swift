import Foundation

class Transformation {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func rotate(angle: Double) -> Transformation {
        let cosA = cos(angle)
        let sinA = sin(angle)
        let newX = self.x * cosA - self.y * sinA
        let newY = self.x * sinA + self.y * cosA
        self.x = newX
        self.y = newY
        return self
    }

    func translate(dx: Double, dy: Double, dz: Double) -> Transformation {
        self.x += dx
        self.y += dy
        self.z += dz
        return self
    }

    func scale(sx: Double, sy: Double, sz: Double) -> Transformation {
        self.x *= sx
        self.y *= sy
        self.z *= sz
        return self
    }
}

func transform_sequence(obj: Transformation, rotations: [Double], translations: [(Double, Double, Double)], scales: [(Double, Double, Double)]) -> Transformation {
    for angle in rotations {
        obj.rotate(angle: angle)
    }
    for (dx, dy, dz) in translations {
        obj.translate(dx: dx, dy: dy, dz: dz)
    }
    for (sx, sy, sz) in scales {
        obj.scale(sx: sx, sy: sy, sz: sz)
    }
    return obj
}

func main() {
    let obj = Transformation(x: 1.0, y: 2.0, z: 3.0)
    let rotations = [0.1, 0.2, 0.3]
    let translations = [(0.5, 0.5, 0.5), (1.0, 1.0, 1.0)]
    let scales = [(1.5, 1.5, 1.5), (2.0, 2.0, 2.0)]
    while true {
        let transformed_obj = transform_sequence(obj: obj, rotations: rotations, translations: translations, scales: scales)
        print("Transformed coordinates: (\(transformed_obj.x), \(transformed_obj.y), \(transformed_obj.z))")
    }
}

main()