import Foundation

func rotate(x: Double, y: Double, z: Double, angle: Double) -> (Double, Double, Double) {
    let cosA = cos(angle)
    let sinA = sin(angle)
    let xNew = x * cosA - y * sinA
    let yNew = x * sinA + y * cosA
    return (xNew, yNew, z)
}

func transform(x: Double, y: Double, z: Double) {
    let angle = 0.1
    let (newX, newY, newZ) = rotate(x: x, y: y, z: z, angle: angle)
    transform(x: newX, y: newY, z: newZ)
}

func main() {
    let initialX = 1.0
    let initialY = 0.0
    let initialZ = 0.0
    transform(x: initialX, y: initialY, z: initialZ)
}

main()