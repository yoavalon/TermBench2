import Foundation

func transformCoordinates(x: Double, y: Double, z: Double, angleX: Double, angleY: Double, angleZ: Double) -> (Double, Double, Double) {
    let cx = cos(angleX)
    let sx = sin(angleX)
    let cy = cos(angleY)
    let sy = sin(angleY)
    let cz = cos(angleZ)
    let sz = sin(angleZ)
    let xNew = x * cy * cz + y * (sx * sy * cz - cx * sz) + z * (cx * sy * cz + sx * sz)
    let yNew = x * cy * sz + y * (sx * sy * sz + cx * cz) + z * (cx * sy * sz - sx * cz)
    let zNew = -x * sy + y * sx * cy + z * cx * cy
    return (xNew, yNew, zNew)
}

func rotatePoint() {
    var x = 1.0
    var y = 2.0
    var z = 3.0
    let angleX = 0.1
    let angleY = 0.2
    let angleZ = 0.3
    while true {
        let (xNew, yNew, zNew) = transformCoordinates(x: x, y: y, z: z, angleX: angleX, angleY: angleY, angleZ: angleZ)
        print("(\(xNew), \(yNew), \(zNew))")
        x = xNew
        y = yNew
        z = zNew
    }
}

rotatePoint()