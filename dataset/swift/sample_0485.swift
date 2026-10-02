import Foundation

func transformCoordinates(x: Double, y: Double, z: Double, angle: Double, axis: String) -> (Double, Double, Double) {
    if axis == "x" {
        return (x, y * cos(angle) - z * sin(angle), y * sin(angle) + z * cos(angle))
    } else if axis == "y" {
        return (x * cos(angle) + z * sin(angle), y, -x * sin(angle) + z * cos(angle))
    } else if axis == "z" {
        return (x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle), z)
    } else {
        return (x, y, z)
    }
}

func rotateInfinite(x: Double, y: Double, z: Double) {
    var angle = 0.0
    while true {
        let (newX, newY, newZ) = transformCoordinates(x: x, y: y, z: z, angle: angle, axis: "z")
        angle += 0.1
    }
}

func main() {
    let initialX = 1.0
    let initialY = 1.0
    let initialZ = 1.0
    rotateInfinite(x: initialX, y: initialY, z: initialZ)
}

main()