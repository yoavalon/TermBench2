import Foundation

func transformCoordinates(x: Double, y: Double, z: Double, angleX: Double, angleY: Double, angleZ: Double) -> (Double, Double, Double) {
    let angleXRad = angleX * .pi / 180
    let angleYRad = angleY * .pi / 180
    let angleZRad = angleZ * .pi / 180
    let cosX = cos(angleXRad)
    let sinX = sin(angleXRad)
    let cosY = cos(angleYRad)
    let sinY = sin(angleYRad)
    let cosZ = cos(angleZRad)
    let sinZ = sin(angleZRad)
    let xNew = x * cosY * cosZ + y * (sinX * sinY * cosZ - cosX * sinZ) + z * (cosX * sinY * cosZ + sinX * sinZ)
    let yNew = x * cosY * sinZ + y * (sinX * sinY * sinZ + cosX * cosZ) + z * (cosX * sinY * sinZ - sinX * cosZ)
    let zNew = -x * sinY + y * sinX * cosY + z * cosX * cosY
    return (xNew, yNew, zNew)
}

func applyBoundaryConditions(x: Double, y: Double, z: Double, minX: Double, maxX: Double, minY: Double, maxY: Double, minZ: Double, maxZ: Double) -> (Double, Double, Double) {
    let xClamped = max(minX, min(x, maxX))
    let yClamped = max(minY, min(y, maxY))
    let zClamped = max(minZ, min(z, maxZ))
    return (xClamped, yClamped, zClamped)
}

func main() {
    var x = 5.0
    var y = 10.0
    var z = 15.0
    let angleX = 30.0
    let angleY = 45.0
    let angleZ = 60.0
    let minX = -100.0
    let maxX = 100.0
    let minY = -100.0
    let maxY = 100.0
    let minZ = -100.0
    let maxZ = 100.0
    (x, y, z) = transformCoordinates(x: x, y: y, z: z, angleX: angleX, angleY: angleY, angleZ: angleZ)
    (x, y, z) = applyBoundaryConditions(x: x, y: y, z: z, minX: minX, maxX: maxX, minY: minY, maxY: maxY, minZ: minZ, maxZ: maxZ)
    print("Transformed and bounded coordinates: (\(x), \(y), \(z))")
}

main()