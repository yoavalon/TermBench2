import Foundation

func transformPoint(x: Double, y: Double, z: Double, angleX: Double, angleY: Double, angleZ: Double) -> (Double, Double, Double) {
    let cx = cos(angleX)
    let cy = cos(angleY)
    let cz = cos(angleZ)
    let sx = sin(angleX)
    let sy = sin(angleY)
    let sz = sin(angleZ)
    let xNew = cx * (cy * z + sy * (sx * y + cx * z)) - sx * (cx * y - sx * z)
    let yNew = sy * (cx * z + sx * (sx * y + cx * z)) + cy * (cx * y - sx * z)
    let zNew = cy * (cx * y - sx * z) - sy * (cx * z + sx * (sx * y + cx * z))
    return (xNew, yNew, zNew)
}

func continuousTransform() {
    var x = 0.0
    var y = 0.0
    var z = 0.0
    var angleX = 0.1
    var angleY = 0.2
    var angleZ = 0.3
    while true {
        let (newX, newY, newZ) = transformPoint(x: x, y: y, z: z, angleX: angleX, angleY: angleY, angleZ: angleZ)
        x = newX
        y = newY
        z = newZ
        angleX += 0.01
        angleY += 0.02
        angleZ += 0.03
    }
}

continuousTransform()