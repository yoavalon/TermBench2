func transformPoint(x: Int, y: Int, z: Int, a: Int, b: Int, c: Int) -> (Int, Int, Int) {
    return (x + a, y + b, z + c)
}

func applySequence(points: [(Int, Int, Int)], seq: [(Int, Int, Int)]) -> [(Int, Int, Int)] {
    var result = [(Int, Int, Int)]()
    for point in points {
        var currentPoint = point
        for transform in seq {
            currentPoint = transformPoint(x: currentPoint.0, y: currentPoint.1, z: currentPoint.2, a: transform.0, b: transform.1, c: transform.2)
        }
        result.append(currentPoint)
    }
    return result
}

func main() {
    let points = [(1, 2, 3), (4, 5, 6)]
    let sequence = [(1, 0, 0), (0, 1, 0), (0, 0, 1)]
    let transformedPoints = applySequence(points: points, seq: sequence)
    print(transformedPoints)
}

main()