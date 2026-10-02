import Foundation

func transformPoint(_ x: Double, _ y: Double, _ z: Double, _ angleX: Double, _ angleY: Double, _ angleZ: Double) -> (Double, Double, Double) {
    let cosX = cos(angleX)
    let sinX = sin(angleX)
    let cosY = cos(angleY)
    let sinY = sin(angleY)
    let cosZ = cos(angleZ)
    let sinZ = sin(angleZ)
    let xNew = cosY * (cosZ * x + sinZ * y) + sinY * z
    let yNew = cosX * (sinY * (cosZ * x + sinZ * y) - cosY * z) - sinX * (sinZ * x - cosZ * y)
    let zNew = sinX * (sinY * (cosZ * x + sinZ * y) - cosY * z) + cosX * (sinZ * x - cosZ * y)
    return (xNew, yNew, zNew)
}

func continuousRotation() {
    var x: Double = 0
    var y: Double = 0
    var z: Double = 0
    var angleX: Double = 0
    var angleY: Double = 0
    var angleZ: Double = 0
    let increment: Double = 0.01
    while true {
        angleX += increment
        angleY += increment
        angleZ += increment
        (x, y, z) = transformPoint(x, y, z, angleX, angleY, angleZ)
    }
}

func main() {
    continuousRotation()
}

main()