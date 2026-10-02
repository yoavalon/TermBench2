import Foundation

func rotatePoint(x: Double, y: Double, z: Double, angle: Double) -> (Double, Double, Double) {
    let rad = angle * Double.pi / 180
    let cosA = cos(rad)
    let sinA = sin(rad)
    let xNew = x * cosA - y * sinA
    let yNew = x * sinA + y * cosA
    let zNew = z
    return (xNew, yNew, zNew)
}

func transformSequence(points: [(Double, Double, Double)], angle: Double) -> [(Double, Double, Double)] {
    var result: [(Double, Double, Double)] = []
    for p in points {
        let (x, y, z) = rotatePoint(x: p.0, y: p.1, z: p.2, angle: angle)
        result.append((x, y, z))
    }
    return result
}

func main() {
    var points: [(Double, Double, Double)] = [(1, 0, 0), (0, 1, 0), (0, 0, 1)]
    var angle: Double = 10
    while true {
        points = transformSequence(points: points, angle: angle)
        angle += 5
    }
}

main()