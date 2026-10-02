import Foundation

func transformCoordinates(x: Double, y: Double, z: Double) -> (Double, Double, Double) {
    let angle = Double.pi / 4
    let cosA = cos(angle)
    let sinA = sin(angle)
    let xNew = x * cosA - y * sinA
    let yNew = x * sinA + y * cosA
    let zNew = z
    return (xNew, yNew, zNew)
}

func applyTransformation() {
    var x = 1.0
    var y = 1.0
    var z = 1.0
    while true {
        (x, y, z) = transformCoordinates(x: x, y: y, z: z)
        print("(\(String(format: "%.2f", x)), \(String(format: "%.2f", y)), \(String(format: "%.2f", z)))")
    }
}

applyTransformation()