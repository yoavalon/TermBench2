import Foundation

class Transformation {
    func rotate(x: Double, y: Double, z: Double, angle: Double) -> (Double, Double, Double) {
        let cosA = cos(angle)
        let sinA = sin(angle)
        let newX = x * cosA - y * sinA
        let newY = x * sinA + y * cosA
        let newZ = z
        return (newX, newY, newZ)
    }

    func scale(x: Double, y: Double, z: Double, factor: Double) -> (Double, Double, Double) {
        let newX = x * factor
        let newY = y * factor
        let newZ = z * factor
        return (newX, newY, newZ)
    }

    func translate(x: Double, y: Double, z: Double, dx: Double, dy: Double, dz: Double) -> (Double, Double, Double) {
        let newX = x + dx
        let newY = y + dy
        let newZ = z + dz
        return (newX, newY, newZ)
    }
}

func transformPoint(transformation: Transformation, x: Double, y: Double, z: Double) -> (Double, Double, Double) {
    let (x, y, z) = transformation.rotate(x: x, y: y, z: z, angle: 0.1)
    let (x, y, z) = transformation.scale(x: x, y: y, z: z, factor: 1.1)
    let (x, y, z) = transformation.translate(x: x, y: y, z: z, dx: 1, dy: 1, dz: 1)
    return (x, y, z)
}

func recursiveTransform(transformation: Transformation, x: Double, y: Double, z: Double) {
    let (x, y, z) = transformPoint(transformation: transformation, x: x, y: y, z: z)
    recursiveTransform(transformation: transformation, x: x, y: y, z: z)
}

func main() {
    let transformation = Transformation()
    let (x, y, z) = (1.0, 1.0, 1.0)
    recursiveTransform(transformation: transformation, x: x, y: y, z: z)
}

main()