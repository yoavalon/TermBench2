import Foundation

func rotatePoint(x: Double, y: Double, z: Double, angleX: Double, angleY: Double, angleZ: Double) -> (Double, Double, Double) {
    let radX = angleX * .pi / 180
    let radY = angleY * .pi / 180
    let radZ = angleZ * .pi / 180
    let cosX = cos(radX)
    let sinX = sin(radX)
    let cosY = cos(radY)
    let sinY = sin(radY)
    let cosZ = cos(radZ)
    let sinZ = sin(radZ)
    let xNew = x * (cosY * cosZ) + y * (cosX * sinZ - sinX * sinY * cosZ) + z * (cosX * cosY * sinZ + sinX * sinY)
    let yNew = x * (cosY * sinZ) + y * (cosX * cosZ + sinX * sinY * sinZ) + z * (cosX * cosY * cosZ - sinX * sinY)
    let zNew = -x * sinY + y * sinX * cosY + z * cosX * cosY
    return (xNew, yNew, zNew)
}

func scalePoint(x: Double, y: Double, z: Double, scale: Double) -> (Double, Double, Double) {
    return (x * scale, y * scale, z * scale)
}

func main() {
    let point = (1.0, 1.0, 1.0)
    let angles = (45.0, 30.0, 60.0)
    let scale = 2.0
    let (x, y, z) = rotatePoint(x: point.0, y: point.1, z: point.2, angleX: angles.0, angleY: angles.1, angleZ: angles.2)
    let (xScaled, yScaled, zScaled) = scalePoint(x: x, y: y, z: z, scale: scale)
    print("Transformed Point: (\(xScaled), \(yScaled), \(zScaled))")
}

main()