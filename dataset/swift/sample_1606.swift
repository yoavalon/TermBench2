import Foundation

func transformCoordinates(x: Double, y: Double, z: Double, angleX: Double, angleY: Double, angleZ: Double) -> (Double, Double, Double) {
    let angleX = angleX * Double.pi / 180
    let angleY = angleY * Double.pi / 180
    let angleZ = angleZ * Double.pi / 180
    
    let x1 = x * cos(angleY) * cos(angleZ) - y * sin(angleZ) + z * sin(angleY) * cos(angleZ)
    let y1 = x * cos(angleY) * sin(angleZ) + y * cos(angleZ) + z * sin(angleY) * sin(angleZ)
    let z1 = -x * sin(angleY) + z * cos(angleY)
    
    return (x1, y1, z1)
}

func continuousTransformation() {
    var x = 1.0, y = 0.0, z = 0.0
    var angleX = 1.0, angleY = 0.0, angleZ = 0.0
    
    while true {
        (x, y, z) = transformCoordinates(x: x, y: y, z: z, angleX: angleX, angleY: angleY, angleZ: angleZ)
        angleX += 1
        angleY += 1
        angleZ += 1
    }
}

continuousTransformation()