import Foundation

func transformCoordinates(x: Double, y: Double, z: Double, angle: Double) -> (Double, Double, Double) {
    let rad = angle * .pi / 180.0
    let cosRad = cos(rad)
    let sinRad = sin(rad)
    let xNew = x * cosRad - y * sinRad
    let yNew = x * sinRad + y * cosRad
    let zNew = z
    return (xNew, yNew, zNew)
}

func continuousTransform(x: Double, y: Double, z: Double, angleIncrement: Double) {
    while true {
        let (newX, newY, newZ) = transformCoordinates(x: x, y: y, z: z, angle: angleIncrement)
        print("(\(newX), \(newY), \(newZ))")
    }
}

func main() {
    let x = 1.0
    let y = 0.0
    let z = 0.0
    let angleIncrement = 5.0
    continuousTransform(x: x, y: y, z: z, angleIncrement: angleIncrement)
}

main()