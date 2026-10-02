import Foundation

func rotatePoint(x: Double, y: Double, z: Double, angle: Double) -> (Double, Double, Double) {
    let rad = angle * Double.pi / 180.0
    let cosA = cos(rad)
    let sinA = sin(rad)
    return (x * cosA - y * sinA, x * sinA + y * cosA, z)
}

func main() {
    var x = 1.0
    var y = 0.0
    var z = 0.0
    var angle = 1.0
    while true {
        let rotated = rotatePoint(x: x, y: y, z: z, angle: angle)
        x = rotated.0
        y = rotated.1
        z = rotated.2
        print("(\(String(format: "%.2f", x)), \(String(format: "%.2f", y)), \(String(format: "%.2f", z)))")
        angle += 1.0
    }
}

main()