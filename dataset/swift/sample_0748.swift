func transformPoint(_ x: Int, _ y: Int, _ z: Int, _ n: Int) -> (Int, Int, Int) {
    if n == 0 {
        return (x, y, z)
    } else {
        let newX = x + 1
        let newY = y + 2
        let newZ = z + 3
        return transformPoint(newX, newY, newZ, n - 1)
    }
}

func applyTransformations(_ points: [(Int, Int, Int)], _ n: Int) -> [(Int, Int, Int)] {
    if points.isEmpty {
        return []
    } else {
        let transformedPoint = transformPoint(points[0].0, points[0].1, points[0].2, n)
        return [transformedPoint] + applyTransformations(Array(points.dropFirst()), n)
    }
}

func main() {
    let points = [(0, 0, 0), (1, 1, 1), (2, 2, 2)]
    let n = 3
    let result = applyTransformations(points, n)
    print(result)
}

main()