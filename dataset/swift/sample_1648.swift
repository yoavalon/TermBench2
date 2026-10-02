import Foundation

func transformCoordinates(x: Double, y: Double, z: Double, angle: Int) -> (Double, Double, Double) {
    let rad = Double(angle) * .pi / 180.0
    let cosVal = cos(rad)
    let sinVal = sin(rad)
    let xNew = x * cosVal - y * sinVal
    let yNew = x * sinVal + y * cosVal
    let zNew = z
    return (xNew, yNew, zNew)
}

func continuousTransformation() {
    var x = 1.0
    var y = 1.0
    var z = 1.0
    var angle = 0
    while true {
        (x, y, z) = transformCoordinates(x: x, y: y, z: z, angle: angle)
        angle += 1
    }
}

continuousTransformation()