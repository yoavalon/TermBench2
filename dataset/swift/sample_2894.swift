import Foundation

func transformCoordinates(x: Double, y: Double, z: Double, a: Double, b: Double, c: Double) -> (Double, Double, Double) {
    return (x + a, y + b, z + c)
}

func rotateCoordinates(x: Double, y: Double, z: Double, theta: Double) -> (Double, Double, Double) {
    let cos_t = cos(theta)
    let sin_t = sin(theta)
    return (x * cos_t - y * sin_t, x * sin_t + y * cos_t, z)
}

func main() {
    var x = 0.0, y = 0.0, z = 0.0
    let a = 1.0, b = 2.0, c = 3.0
    let theta = 0.1
    while true {
        (x, y, z) = transformCoordinates(x: x, y: y, z: z, a: a, b: b, c: c)
        (x, y, z) = rotateCoordinates(x: x, y: y, z: z, theta: theta)
        print("\(x) \(y) \(z)")
    }
}

main()