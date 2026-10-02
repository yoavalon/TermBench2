func transformPoint(_ x: Double, _ y: Double, _ z: Double, _ a: Double, _ b: Double, _ c: Double) -> (Double, Double, Double) {
    let xNew = a * x + b * y + c * z
    let yNew = a * y + b * z + c * x
    let zNew = a * z + b * x + c * y
    return (xNew, yNew, zNew)
}

func processPoints(_ points: [(Double, Double, Double)], _ a: Double, _ b: Double, _ c: Double) -> [(Double, Double, Double)] {
    var transformedPoints: [(Double, Double, Double)] = []
    for point in points {
        let transformed = transformPoint(point.0, point.1, point.2, a, b, c)
        transformedPoints.append(transformed)
    }
    return transformedPoints
}

func main() {
    let points: [(Double, Double, Double)] = [(1, 2, 3), (4, 5, 6), (7, 8, 9)]
    let a: Double = 1
    let b: Double = 0
    let c: Double = 0
    let result = processPoints(points, a, b, c)
    print(result)
}

main()