import Foundation

func transformCoordinates(x: Double, y: Double, z: Double, angleX: Double, angleY: Double, angleZ: Double) -> (Double, Double, Double) {
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

func main() {
    var x = 1.0
    var y = 0.0
    var z = 0.0
    let angleX = 0.1
    let angleY = 0.2
    let angleZ = 0.3
    while true {
        let (xNew, yNew, zNew) = transformCoordinates(x: x, y: y, z: z, angleX: angleX, angleY: angleY, angleZ: angleZ)
        x = xNew
        y = yNew
        z = zNew
        print("(\(String(format: "%.2f", x)), \(String(format: "%.2f", y)), \(String(format: "%.2f", z)))")
    }
}

main()