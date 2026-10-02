import Foundation

func transformCoordinates(x: Double, y: Double, z: Double, angle: Double) -> (Double, Double, Double) {
    let cosA = cos(angle)
    let sinA = sin(angle)
    let xNew = x * cosA - y * sinA
    let yNew = x * sinA + y * cosA
    return (xNew, yNew, z)
}

func main() {
    var angle = 0.0
    var (x, y, z) = (1.0, 0.0, 0.0)
    while true {
        (x, y, z) = transformCoordinates(x: x, y: y, z: z, angle: angle)
        angle += 0.01
    }
}

main()