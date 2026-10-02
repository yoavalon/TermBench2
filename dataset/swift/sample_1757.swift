import Foundation

class CoordinateTransform {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func translate(dx: Double, dy: Double, dz: Double) {
        self.x += dx
        self.y += dy
        self.z += dz
    }

    func rotate_x(angle: Double) {
        let rad = angle * .pi / 180
        let newY = self.y * cos(rad) - self.z * sin(rad)
        let newZ = self.y * sin(rad) + self.z * cos(rad)
        self.y = newY
        self.z = newZ
    }

    func rotate_y(angle: Double) {
        let rad = angle * .pi / 180
        let newX = self.x * cos(rad) + self.z * sin(rad)
        let newZ = -self.x * sin(rad) + self.z * cos(rad)
        self.x = newX
        self.z = newZ
    }

    func rotate_z(angle: Double) {
        let rad = angle * .pi / 180
        let newX = self.x * cos(rad) - self.y * sin(rad)
        let newY = self.x * sin(rad) + self.y * cos(rad)
        self.x = newX
        self.y = newY
    }
}

func transform_sequence(coord: CoordinateTransform, sequence: [(String, Any)]) {
    for action in sequence {
        switch action {
        case let ("translate", dx, dy, dz):
            coord.translate(dx: dx as! Double, dy: dy as! Double, dz: dz as! Double)
        case let ("rotate_x", angle):
            coord.rotate_x(angle: angle as! Double)
        case let ("rotate_y", angle):
            coord.rotate_y(angle: angle as! Double)
        case let ("rotate_z", angle):
            coord.rotate_z(angle: angle as! Double)
        default:
            break
        }
    }
}

func main() {
    let coord = CoordinateTransform(x: 1, y: 2, z: 3)
    let sequence: [(String, Any)] = [("translate", 1, 1, 1), ("rotate_x", 45), ("rotate_y", 45), ("rotate_z", 45), ("translate", -1, -1, -1)]
    while true {
        transform_sequence(coord: coord, sequence: sequence)
        print("(\(coord.x), \(coord.y), \(coord.z))")
    }
}

main()