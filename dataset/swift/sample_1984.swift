import Foundation

func transformCoordinates(_ x: Double, _ y: Double, _ z: Double, _ angle: Double) -> (Double, Double, Double) {
    let rad = angle * Double.pi / 180.0
    let cos_a = cos(rad)
    let sin_a = sin(rad)
    let new_x = x * cos_a - y * sin_a
    let new_y = x * sin_a + y * cos_a
    let new_z = z
    return (new_x, new_y, new_z)
}

func calculateDistance(_ x1: Double, _ y1: Double, _ z1: Double, _ x2: Double, _ y2: Double, _ z2: Double) -> Double {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2))
}

func main() {
    let x = 1.0
    let y = 2.0
    let z = 3.0
    let angle = 30.0
    let (x_t, y_t, z_t) = transformCoordinates(x, y, z, angle)
    let d = calculateDistance(x, y, z, x_t, y_t, z_t)
    print("Transformed Coordinates: (\(x_t), \(y_t), \(z_t))")
    print("Distance: \(d)")
}

main()