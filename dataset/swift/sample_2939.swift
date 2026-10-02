import Foundation

class Coordinate {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func rotateX(angle: Double) {
        let angleRad = angle * Double.pi / 180
        let cosVal = cos(angleRad)
        let sinVal = sin(angleRad)
        self.y = self.y * cosVal - self.z * sinVal
        self.z = self.y * sinVal + self.z * cosVal
    }

    func rotateY(angle: Double) {
        let angleRad = angle * Double.pi / 180
        let cosVal = cos(angleRad)
        let sinVal = sin(angleRad)
        self.x = self.x * cosVal + self.z * sinVal
        self.z = -self.x * sinVal + self.z * cosVal
    }

    func rotateZ(angle: Double) {
        let angleRad = angle * Double.pi / 180
        let cosVal = cos(angleRad)
        let sinVal = sin(angleRad)
        self.x = self.x * cosVal - self.y * sinVal
        self.y = self.x * sinVal + self.y * cosVal
    }
}

func generateSequence(start: (Double, Double, Double), increment: (Double, Double, Double), length: Int) -> [(Double, Double, Double)] {
    var sequence = [(Double, Double, Double)]()
    var current = start
    for _ in 0..<length {
        sequence.append(current)
        current = (current.0 + increment.0, current.1 + increment.1, current.2 + increment.2)
    }
    return sequence
}

func applyTransformation(sequence: inout [(Double, Double, Double)], angleX: Double, angleY: Double, angleZ: Double) {
    for i in 0..<sequence.count {
        let coordObj = Coordinate(x: sequence[i].0, y: sequence[i].1, z: sequence[i].2)
        coordObj.rotateX(angle: angleX)
        coordObj.rotateY(angle: angleY)
        coordObj.rotateZ(angle: angleZ)
        sequence[i] = (coordObj.x, coordObj.y, coordObj.z)
    }
}

func main() {
    let startPoint = (0.0, 0.0, 0.0)
    let increment = (1.0, 1.0, 1.0)
    let sequenceLength = 100
    var sequence = generateSequence(start: startPoint, increment: increment, length: sequenceLength)
    var angleX = 5.0
    var angleY = 5.0
    var angleZ = 5.0
    while true {
        applyTransformation(sequence: &sequence, angleX: angleX, angleY: angleY, angleZ: angleZ)
        angleX += 1.0
        angleY += 1.0
        angleZ += 1.0
    }
}

main()