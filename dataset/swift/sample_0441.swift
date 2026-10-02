import Foundation

func transformCoordinates(x: Double, y: Double, z: Double, angleX: Double, angleY: Double, angleZ: Double) -> (Double, Double, Double) {
    let radX = angleX * Double.pi / 180.0
    let radY = angleY * Double.pi / 180.0
    let radZ = angleZ * Double.pi / 180.0
    
    let cosX = cos(radX)
    let sinX = sin(radX)
    let cosY = cos(radY)
    let sinY = sin(radY)
    let cosZ = cos(radZ)
    let sinZ = sin(radZ)
    
    let x2 = x * cosY * cosZ + y * (cosX * sinZ + sinX * sinY * cosZ) + z * (sinX * sinZ - cosX * sinY * cosZ)
    let y2 = -x * cosY * sinZ + y * (cosX * cosZ - sinX * sinY * sinZ) + z * (sinX * cosZ + cosX * sinY * sinZ)
    let z2 = x * sinY + y * (-sinX * cosY) + z * (cosX * cosY)
    
    return (x2, y2, z2)
}

func rotateForever() {
    var x = 1.0
    var y = 0.0
    var z = 0.0
    var angleX = 0.0
    var angleY = 0.0
    var angleZ = 1.0
    
    while true {
        (x, y, z) = transformCoordinates(x: x, y: y, z: z, angleX: angleX, angleY: angleY, angleZ: angleZ)
        angleX += 1.0
        angleY += 1.0
        angleZ += 1.0
    }
}

rotateForever()