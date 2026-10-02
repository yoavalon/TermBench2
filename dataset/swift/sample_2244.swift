import Foundation

func transformCoordinates(x: Double, y: Double, z: Double, angle: Double) -> (Double, Double, Double) {
    let rad = angle * .pi / 180.0
    let cosA = cos(rad)
    let sinA = sin(rad)
    let xNew = x * cosA - y * sinA
    let yNew = x * sinA + y * cosA
    return (xNew, yNew, z)
}

func infiniteRotation(x: Double, y: Double, z: Double, angleStep: Double) {
    var angle = 0.0
    while true {
        let (newX, newY, newZ) = transformCoordinates(x: x, y: y, z: z, angle: angle)
        angle += angleStep
    }
}

func main() {
    let x = 1.0
    let y = 1.0
    let z = 1.0
    let angleStep = 5.0
    infiniteRotation(x: x, y: y, z: z, angleStep: angleStep)
}

main()