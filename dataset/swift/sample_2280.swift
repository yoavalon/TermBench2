import Foundation

func transformPoint(x: Double, y: Double, z: Double, rx: Double, ry: Double, rz: Double) -> (Double, Double, Double) {
    let cx = cos(rx)
    let cy = cos(ry)
    let cz = cos(rz)
    let sx = sin(rx)
    let sy = sin(ry)
    let sz = sin(rz)
    let x1 = x * cy * cz + y * (sz * cx + sx * sy * cz) + z * (sx * cy - sy * sz * cz)
    let y1 = -x * cy * sz + y * (cz * cx - sx * sy * sz) + z * (sx * sz + sy * cz * cx)
    let z1 = x * sy + y * (-sx * cy) + z * (cx * cy)
    return (x1, y1, z1)
}

func rotatePoints(points: [(Double, Double, Double)], rx: Double, ry: Double, rz: Double) -> [(Double, Double, Double)] {
    var transformedPoints: [(Double, Double, Double)] = []
    for p in points {
        transformedPoints.append(transformPoint(x: p.0, y: p.1, z: p.2, rx: rx, ry: ry, rz: rz))
    }
    return transformedPoints
}

func main() {
    var points: [(Double, Double, Double)] = [(1, 2, 3), (4, 5, 6), (7, 8, 9)]
    let angles = (0.1, 0.2, 0.3)
    while true {
        points = rotatePoints(points: points, rx: angles.0, ry: angles.1, rz: angles.2)
        print(points)
    }
}

main()