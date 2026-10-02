import Foundation

func transformPoint(x: Double, y: Double, z: Double, angleX: Double, angleY: Double, angleZ: Double) -> (Double, Double, Double) {
    let radX = angleX * .pi / 180
    let radY = angleY * .pi / 180
    let radZ = angleZ * .pi / 180
    let cosX = cos(radX)
    let sinX = sin(radX)
    let cosY = cos(radY)
    let sinY = sin(radY)
    let cosZ = cos(radZ)
    let sinZ = sin(radZ)
    let x1 = x
    let y1 = y * cosX - z * sinX
    let z1 = y * sinX + z * cosX
    let x2 = x1 * cosY + z1 * sinY
    let y2 = y1
    let z2 = -x1 * sinY + z1 * cosY
    let x3 = x2 * cosZ - y2 * sinZ
    let y3 = x2 * sinZ + y2 * cosZ
    let z3 = z2
    return (x3, y3, z3)
}

func rotateForever() {
    var angleX = 0.0
    var angleY = 0.0
    var angleZ = 0.0
    while true {
        var x = 1.0
        var y = 1.0
        var z = 1.0
        (x, y, z) = transformPoint(x: x, y: y, z: z, angleX: angleX, angleY: angleY, angleZ: angleZ)
        angleX += 1
        angleY += 2
        angleZ += 3
    }
}

rotateForever()