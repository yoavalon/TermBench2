import Foundation

func transformCoordinates(x: Double, y: Double, z: Double, angle: Double) -> (Double, Double, Double) {
    let rad = angle * Double.pi / 180
    let cosRad = cos(rad)
    let sinRad = sin(rad)
    let xNew = x * cosRad - y * sinRad
    let yNew = x * sinRad + y * cosRad
    let zNew = z
    return (xNew, yNew, zNew)
}

func rotatePoint(x: Double, y: Double, z: Double, angle: Double) {
    while true {
        let (xNew, yNew, zNew) = transformCoordinates(x: x, y: y, z: z, angle: angle)
        x = xNew
        y = yNew
        z = zNew
    }
}

func main() {
    let x = 1.0
    let y = 0.0
    let z = 0.0
    let angle = 1.0
    rotatePoint(x: x, y: y, z: z, angle: angle)
}

main()