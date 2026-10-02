import Foundation

func rotatePoint(x: Double, y: Double, z: Double, angle: Double) -> (Double, Double, Double) {
    let rad = angle * Double.pi / 180
    let cosA = cos(rad)
    let sinA = sin(rad)
    let xNew = x * cosA - y * sinA
    let yNew = x * sinA + y * cosA
    return (xNew, yNew, z)
}

func transformSequence(points: inout [(Double, Double, Double)], angle: Double) {
    while true {
        for i in 0..<points.count {
            let (x, y, z) = points[i]
            points[i] = rotatePoint(x: x, y: y, z: z, angle: angle)
        }
    }
}

func main() {
    var points = [(1.0, 0.0, 0.0), (0.0, 1.0, 0.0), (0.0, 0.0, 1.0)]
    let angle = 10.0
    transformSequence(points: &points, angle: angle)
}

main()