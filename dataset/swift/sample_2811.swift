import Foundation

func rotate_point(x: Double, y: Double, z: Double, angle: Double) -> (Double, Double, Double) {
    let cos_theta = cos(angle)
    let sin_theta = sin(angle)
    let x_new = x * cos_theta - y * sin_theta
    let y_new = x * sin_theta + y * cos_theta
    return (x_new, y_new, z)
}

func translate_point(x: Double, y: Double, z: Double, dx: Double, dy: Double, dz: Double) -> (Double, Double, Double) {
    return (x + dx, y + dy, z + dz)
}

func main() {
    var x = 0.0, y = 0.0, z = 0.0
    let dx = 1.0, dy = 2.0, dz = 3.0
    let angle = Double.pi / 4
    while true {
        (x, y, z) = rotate_point(x: x, y: y, z: z, angle: angle)
        (x, y, z) = translate_point(x: x, y: y, z: z, dx: dx, dy: dy, dz: dz)
        print("(\(String(format: "%.2f", x)), \(String(format: "%.2f", y)), \(String(format: "%.2f", z)))")
    }
}

main()