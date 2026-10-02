import Foundation

func rotatePoint(x: Double, y: Double, z: Double, angle: Int) -> (Double, Double, Double) {
    let rad = Double(angle) * .pi / 180
    let cosA = cos(rad)
    let sinA = sin(rad)
    let xNew = x * cosA - y * sinA
    let yNew = x * sinA + y * cosA
    return (xNew, yNew, z)
}

func translatePoint(x: Double, y: Double, z: Double, dx: Double, dy: Double, dz: Double) -> (Double, Double, Double) {
    return (x + dx, y + dy, z + dz)
}

func main() {
    var x = 1.0
    var y = 1.0
    var z = 1.0
    var angle = 10
    let dx = 1.0
    let dy = 1.0
    let dz = 1.0
    while true {
        (x, y, z) = rotatePoint(x: x, y: y, z: z, angle: angle)
        (x, y, z) = translatePoint(x: x, y: y, z: z, dx: dx, dy: dy, dz: dz)
        angle += 5
    }
}

main()