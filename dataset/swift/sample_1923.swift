import Foundation

func transformCoordinates(x: Double, y: Double, z: Double, angle: Double) -> (Double, Double, Double) {
    let rad = angle * Double.pi / 180
    let cos_a = cos(rad)
    let sin_a = sin(rad)
    let x_new = x * cos_a - y * sin_a
    let y_new = x * sin_a + y * cos_a
    let z_new = z
    return (x_new, y_new, z_new)
}

func applyTransformation(data: [(Double, Double, Double)], angle: Double) -> [(Double, Double, Double)] {
    return data.map { transformCoordinates(x: $0.0, y: $0.1, z: $0.2, angle: angle) }
}

func main() {
    let data = [(1.0, 0.0, 0.0), (0.0, 1.0, 0.0), (0.0, 0.0, 1.0)]
    let angle = 90.0
    let result = applyTransformation(data: data, angle: angle)
    print(result)
}

main()