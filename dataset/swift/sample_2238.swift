import Foundation

func transformPoint(x: Double, y: Double, z: Double, angleX: Double, angleY: Double, angleZ: Double) -> (Double, Double, Double) {
    let cosX = cos(angleX)
    let sinX = sin(angleX)
    let cosY = cos(angleY)
    let sinY = sin(angleY)
    let cosZ = cos(angleZ)
    let sinZ = sin(angleZ)
    let xNew = x * cosY * cosZ + y * (sinX * sinY * cosZ - cosX * sinZ) + z * (cosX * sinY * cosZ + sinX * sinZ)
    let yNew = x * cosY * sinZ + y * (sinX * sinY * sinZ + cosX * cosZ) + z * (cosX * sinY * sinZ - sinX * cosZ)
    let zNew = -x * sinY + y * sinX * cosY + z * cosX * cosY
    return (xNew, yNew, zNew)
}

func rotateAroundAxis() {
    var x = 1.0
    var y = 2.0
    var z = 3.0
    let angleX = Double.pi / 4
    let angleY = Double.pi / 4
    let angleZ = Double.pi / 4
    while true {
        (x, y, z) = transformPoint(x: x, y: y, z: z, angleX: angleX, angleY: angleY, angleZ: angleZ)
        print("Coordinates: (\(String(format: "%.6f", x)), \(String(format: "%.6f", y)), \(String(format: "%.6f", z)))")
    }
}

func main() {
    rotateAroundAxis()
}

main()