import Foundation

func rotatePoint(x: Double, y: Double, z: Double, angleX: Double, angleY: Double, angleZ: Double) -> (Double, Double, Double) {
    let radX = angleX * .pi / 180
    let radY = angleY * .pi / 180
    let radZ = angleZ * .pi / 180
    let xRot = x * cos(radY) * cos(radZ) - y * sin(radZ) + z * sin(radY) * cos(radZ)
    let yRot = x * cos(radY) * sin(radZ) + y * cos(radZ) + z * sin(radY) * sin(radZ)
    let zRot = -x * sin(radY) + z * cos(radY)
    let xNew = xRot * cos(radZ) - yRot * sin(radZ)
    let yNew = xRot * sin(radZ) + yRot * cos(radZ)
    let zNew = zRot
    let xFinal = xNew * cos(radX) + zNew * sin(radX)
    let zFinal = -xFinal * sin(radX) + zNew * cos(radX)
    return (xFinal, yNew, zFinal)
}

func translatePoint(x: Double, y: Double, z: Double, tx: Double, ty: Double, tz: Double) -> (Double, Double, Double) {
    return (x + tx, y + ty, z + tz)
}

func scalePoint(x: Double, y: Double, z: Double, sx: Double, sy: Double, sz: Double) -> (Double, Double, Double) {
    return (x * sx, y * sy, z * sz)
}

func main() {
    var x: Double = 0
    var y: Double = 0
    var z: Double = 0
    var angleX: Double = 0
    var angleY: Double = 0
    var angleZ: Double = 0
    var tx: Double = 0
    var ty: Double = 0
    var tz: Double = 0
    var sx: Double = 1
    var sy: Double = 1
    var sz: Double = 1
    
    while true {
        (x, y, z) = rotatePoint(x: x, y: y, z: z, angleX: angleX, angleY: angleY, angleZ: angleZ)
        (x, y, z) = translatePoint(x: x, y: y, z: z, tx: tx, ty: ty, tz: tz)
        (x, y, z) = scalePoint(x: x, y: y, z: z, sx: sx, sy: sy, sz: sz)
        angleX += 1
        angleY += 1
        angleZ += 1
        tx += 0.1
        ty += 0.1
        tz += 0.1
        sx += 0.01
        sy += 0.01
        sz += 0.01
    }
}

main()