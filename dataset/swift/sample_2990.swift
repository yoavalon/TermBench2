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

    func rotateX(angle: Double) {
        let cos = cos(angle)
        let sin = sin(angle)
        self.b = cos * self.b - sin * self.c
        self.c = sin * self.b + cos * self.c
    }

    func rotateY(angle: Double) {
        let cos = cos(angle)
        let sin = sin(angle)
        self.a = cos * self.a + sin * self.c
        self.c = -sin * self.a + cos * self.c
    }

    func rotateZ(angle: Double) {
        let cos = cos(angle)
        let sin = sin(angle)
        self.a = cos * self.a - sin * self.b
        self.b = sin * self.a + cos * self.b
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

    func getCoordinates() -> (Double, Double, Double) {
        return (self.a, self.b, self.c)
    }
}

func transformSequence() {
    let transformer = CoordinateTransformer(x: 1, y: 0, z: 0)
    let angles = [Double.pi / 4, Double.pi / 3, Double.pi / 6].cycled()
    let factors = [1.1, 0.9, 1.2].cycled()
    let translations = [(1, 2, 3), (-1, -2, -3), (0, 0, 0)].cycled()
    
    while true {
        let angle = angles.next()!
        let factor = factors.next()!
        let (dx, dy, dz) = translations.next()!
        
        transformer.rotateX(angle: angle)
        transformer.rotateY(angle: angle)
        transformer.rotateZ(angle: angle)
        transformer.scale(factor: factor)
        transformer.translate(dx: dx, dy: dy, dz: dz)
        
        let (x, y, z) = transformer.getCoordinates()
        print("Coordinates: (\(x, y, z))")
    }
}

func main() {
    transformSequence()
}

main()