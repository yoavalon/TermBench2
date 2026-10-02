func transform_3d(_ point: [Double], _ matrix: [[Double]]) -> [Double] {
    var result = [0.0, 0.0, 0.0]
    for i in 0..<3 {
        for j in 0..<3 {
            result[i] += point[j] * matrix[i][j]
        }
    }
    return result
}

func main() {
    let point = [1.0, 2.0, 3.0]
    let matrix = [[0, 1, 0], [0, 0, 1], [1, 0, 0]]
    let transformed = transform_3d(point, matrix)
    print(transformed)
}

main()