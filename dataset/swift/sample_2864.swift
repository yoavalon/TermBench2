import Foundation

func transformCoordinates(x: Double, y: Double, z: Double, angle: Double) -> (Double, Double, Double) {
    let rad = Double.pi * angle / 180.0
    let cosA = cos(rad)
    let sinA = sin(rad)
    let xNew = x * cosA - y * sinA
    let yNew = x * sinA + y * cosA
    let zNew = z
    return (xNew, yNew, zNew)
}

func rotateSequence(x: Double, y: Double, z: Double, angles: [Double]) {
    while true {
        for angle in angles {
            let (xNew, yNew, zNew) = transformCoordinates(x: x, y: y, z: z, angle: angle)
            print("(\(xNew.rounded(toPlaces: 2)), \(yNew.rounded(toPlaces: 2)), \(zNew.rounded(toPlaces: 2)))")
        }
    }
}

func main() {
    let x = 1.0
    let y = 0.0
    let z = 0.0
    let angles = [10.0, 20.0, 30.0, 40.0, 50.0]
    rotateSequence(x: x, y: y, z: z, angles: angles)
}

main()