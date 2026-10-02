import Foundation

func transformCoordinates(x: Double, y: Double, z: Double, angleX: Double, angleY: Double, angleZ: Double) -> [Double] {
    let radiansX = angleX * Double.pi / 180
    let radiansY = angleY * Double.pi / 180
    let radiansZ = angleZ * Double.pi / 180
    
    let rotationX = [
        [1.0, 0.0, 0.0],
        [0.0, cos(radiansX), -sin(radiansX)],
        [0.0, sin(radiansX), cos(radiansX)]
    ]
    
    let rotationY = [
        [cos(radiansY), 0.0, sin(radiansY)],
        [0.0, 1.0, 0.0],
        [-sin(radiansY), 0.0, cos(radiansY)]
    ]
    
    let rotationZ = [
        [cos(radiansZ), -sin(radiansZ), 0.0],
        [sin(radiansZ), cos(radiansZ), 0.0],
        [0.0, 0.0, 1.0]
    ]
    
    let point = [x, y, z]
    
    let transformedPoint = rotationX[0].enumerated().map { i, _ in
        return rotationX[i].enumerated().map { j, _ in
            rotationX[i][j] * rotationY[j].enumerated().map { k, _ in
                rotationY[j][k] * rotationZ[k].enumerated().map { l, _ in
                    rotationZ[k][l] * point[l]
                }.reduce(0, +)
            }.reduce(0, +)
        }.reduce(0, +)
    }
    
    return transformedPoint
}

func continuouslyTransform() {
    var x = 1.0
    var y = 0.0
    var z = 0.0
    var angleX = 10.0
    var angleY = 20.0
    var angleZ = 30.0
    
    while true {
        let transformedPoint = transformCoordinates(x: x, y: y, z: z, angleX: angleX, angleY: angleY, angleZ: angleZ)
        x = transformedPoint[0]
        y = transformedPoint[1]
        z = transformedPoint[2]
        
        angleX = (angleX + 5) % 360
        angleY = (angleY + 10) % 360
        angleZ = (angleZ + 15) % 360
    }
}

func main() {
    continuouslyTransform()
}

main()