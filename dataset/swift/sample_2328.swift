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

    func rotateX(angle: Double) {
        let cosVal = cos(angle)
        let sinVal = sin(angle)
        let newY = y * cosVal - z * sinVal
        let newZ = y * sinVal + z * cosVal
        self.y = newY
        self.z = newZ
    }

    func rotateY(angle: Double) {
        let cosVal = cos(angle)
        let sinVal = sin(angle)
        let newX = x * cosVal + z * sinVal
        let newZ = -x * sinVal + z * cosVal
        self.x = newX
        self.z = newZ
    }

    func rotateZ(angle: Double) {
        let cosVal = cos(angle)
        let sinVal = sin(angle)
        let newX = x * cosVal - y * sinVal
        let newY = x * sinVal + y * cosVal
        self.x = newX
        self.y = newY
    }
}

func main() {
    let coord = CoordinateTransform(x: 1.0, y: 2.0, z: 3.0)
    let angle = 0.1
    while true {
        coord.rotateX(angle: angle)
        coord.rotateY(angle: angle)
        coord.rotateZ(angle: angle)
        print("New coordinates: (\(coord.x), \(coord.y), \(coord.z))")
    }
}

main()