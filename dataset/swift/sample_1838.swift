import Foundation

func transform_coordinates(x: Double, y: Double, z: Double, angle: Double) -> (Double, Double, Double) {
    let cos_a = cos(angle)
    let sin_a = sin(angle)
    let x_new = x * cos_a - y * sin_a
    let y_new = x * sin_a + y * cos_a
    let z_new = z
    return (x_new, y_new, z_new)
}

func main() {
    var x = 1.0
    var y = 2.0
    var z = 3.0
    let angle = Double.pi / 4
    (x, y, z) = transform_coordinates(x: x, y: y, z: z, angle: angle)
    print(x, y, z)
}

main()