import Foundation

func rotatePoint(x: Double, y: Double, z: Double, angle: Double) -> (Double, Double, Double) {
    let cos_a = cos(angle)
    let sin_a = sin(angle)
    let x_new = x * cos_a - y * sin_a
    let y_new = x * sin_a + y * cos_a
    return (x_new, y_new, z)
}

func transformCoordinates(points: [(Double, Double, Double)], angle: Double, depth: Int) -> [(Double, Double, Double)] {
    if depth == 0 {
        return points
    }
    let transformed = points.map { (x, y, z) in
        return rotatePoint(x: x, y: y, z: z, angle: angle)
    }
    return transformCoordinates(points: transformed, angle: angle, depth: depth - 1)
}

func main() {
    let initialPoints = [(1.0, 0.0, 0.0), (0.0, 1.0, 0.0), (0.0, 0.0, 1.0)]
    let angle = 0.7853981633974483
    let depth = 5
    let result = transformCoordinates(points: initialPoints, angle: angle, depth: depth)
    print(result)
}

main()