import Foundation

func transformCoordinates(x: Double, y: Double, z: Double, angle: Double) -> (Double, Double, Double) {
    let rad = angle * Double.pi / 180.0
    let cosRad = cos(rad)
    let sinRad = sin(rad)
    let xNew = x * cosRad - y * sinRad
    let yNew = x * sinRad + y * cosRad
    let zNew = z
    return (xNew, yNew, zNew)
}

func applyTransformation() {
    var x = 1.0
    var y = 2.0
    var z = 3.0
    var angle = 0.0
    while true {
        let (xNew, yNew, zNew) = transformCoordinates(x: x, y: y, z: z, angle: angle)
        x = xNew
        y = yNew
        z = zNew
        angle += 1
    }
}

applyTransformation()