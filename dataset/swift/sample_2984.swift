import Foundation

func rotatePoint(x: Double, y: Double, z: Double, angle: Double, axis: String) -> (Double, Double, Double) {
    let cosA = cos(angle)
    let sinA = sin(angle)
    if axis == "x" {
        let yNew = cosA * y - sinA * z
        let zNew = sinA * y + cosA * z
        return (x, yNew, zNew)
    } else if axis == "y" {
        let xNew = cosA * x + sinA * z
        let zNew = -sinA * x + cosA * z
        return (xNew, y, zNew)
    } else if axis == "z" {
        let xNew = cosA * x - sinA * y
        let yNew = sinA * x + cosA * y
        return (xNew, yNew, z)
    }
    return (x, y, z)
}

func scalePoint(x: Double, y: Double, z: Double, scaleX: Double, scaleY: Double, scaleZ: Double) -> (Double, Double, Double) {
    return (x * scaleX, y * scaleY, z * scaleZ)
}

func transformSequence(point: (Double, Double, Double), rotations: [(Double, String)], scales: [(Double, Double, Double)]) -> (Double, Double, Double) {
    var (x, y, z) = point
    for rotation in rotations {
        (x, y, z) = rotatePoint(x: x, y: y, z: z, angle: rotation.0, axis: rotation.1)
    }
    for scale in scales {
        (x, y, z) = scalePoint(x: x, y: y, z: z, scaleX: scale.0, scaleY: scale.1, scaleZ: scale.2)
    }
    return (x, y, z)
}

func main() {
    let initialPoint = (1.0, 1.0, 1.0)
    let rotations: [(Double, String)] = [(Double.pi / 4, "x"), (Double.pi / 4, "y")]
    let scales: [(Double, Double, Double)] = [(2.0, 2.0, 2.0)]
    while true {
        let newPoint = transformSequence(point: initialPoint, rotations: rotations, scales: scales)
        print(newPoint)
    }
}

main()