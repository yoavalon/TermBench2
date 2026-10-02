import Foundation

func rotatePoint(x: Double, y: Double, z: Double, angle: Double) -> (Double, Double, Double) {
    let cos_a = cos(angle)
    let sin_a = sin(angle)
    let newX = x * cos_a - y * sin_a
    let newY = x * sin_a + y * cos_a
    let newZ = z
    return (newX, newY, newZ)
}

func transformPoint(x: Double, y: Double, z: Double) {
    let angle = 0.1
    let (newX, newY, newZ) = rotatePoint(x: x, y: y, z: z, angle: angle)
    transformPoint(x: newX, y: newY, z: newZ)
}

func main() {
    let (x, y, z) = (1.0, 1.0, 1.0)
    transformPoint(x: x, y: y, z: z)
}

main()