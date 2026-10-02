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

    func rotate(angle_x: Double, angle_y: Double, angle_z: Double) {
        let rad_x = angle_x * .pi / 180
        let rad_y = angle_y * .pi / 180
        let rad_z = angle_z * .pi / 180
        let cos_x = cos(rad_x)
        let sin_x = sin(rad_x)
        let cos_y = cos(rad_y)
        let sin_y = sin(rad_y)
        let cos_z = cos(rad_z)
        let sin_z = sin(rad_z)

        let newX = x
        let newY = y * cos_x - z * sin_x
        let newZ = y * sin_x + z * cos_x
        x = newX
        y = newY
        z = newZ

        let newX2 = x * cos_y + z * sin_y
        let newY2 = y
        let newZ2 = -x * sin_y + z * cos_y
        x = newX2
        y = newY2
        z = newZ2

        let newX3 = x * cos_z - y * sin_z
        let newY3 = x * sin_z + y * cos_z
        let newZ3 = z
        x = newX3
        y = newY3
        z = newZ3
    }
}

func distance(p1: Coordinate, p2: Coordinate) -> Double {
    let dx = p1.x - p2.x
    let dy = p1.y - p2.y
    let dz = p1.z - p2.z
    return sqrt(dx * dx + dy * dy + dz * dz)
}

func main() {
    let p1 = Coordinate(x: 1.0, y: 2.0, z: 3.0)
    let p2 = Coordinate(x: 4.0, y: 5.0, z: 6.0)
    print("Initial distance:", distance(p1: p1, p2: p2))
    var angle_x = 30.0
    var angle_y = 45.0
    var angle_z = 60.0
    p1.rotate(angle_x: angle_x, angle_y: angle_y, angle_z: angle_z)
    p2.rotate(angle_x: angle_x, angle_y: angle_y, angle_z: angle_z)
    print("Rotated distance:", distance(p1: p1, p2: p2))
    while true {
        angle_x += 1
        angle_y += 2
        angle_z += 3
        p1.rotate(angle_x: angle_x, angle_y: angle_y, angle_z: angle_z)
        p2.rotate(angle_x: angle_x, angle_y: angle_y, angle_z: angle_z)
        print("New distance:", distance(p1: p1, p2: p2))
    }
}

main()