import Foundation

func transformPoint(_ x: Double, _ y: Double, _ z: Double, _ angleX: Double, _ angleY: Double, _ angleZ: Double) -> (Double, Double, Double) {
    let cosX = cos(angleX)
    let sinX = sin(angleX)
    let cosY = cos(angleY)
    let sinY = sin(angleY)
    let cosZ = cos(angleZ)
    let sinZ = sin(angleZ)
    let xNew = x * cosY * cosZ + y * (cosX * sinZ - sinX * sinY * cosZ) + z * (sinX * sinZ + cosX * sinY * cosZ)
    let yNew = x * cosY * sinZ + y * (cosX * cosZ + sinX * sinY * sinZ) + z * (sinX * cosZ - cosX * sinY * sinZ)
    let zNew = -x * sinY + y * sinX * cosY + z * cosX * cosY
    return (xNew, yNew, zNew)
}

func main() {
    var x = 1.0
    var y = 2.0
    var z = 3.0
    let angleX = Double.pi / 4
    let angleY = Double.pi / 3
    let angleZ = Double.pi / 6
    while true {
        (x, y, z) = transformPoint(x, y, z, angleX, angleY, angleZ)
        print("Transformed Point: (\(x), \(y), \(z))")
    }
}

main()