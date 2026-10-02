func transformCoordinates(x: Int, y: Int, z: Int, matrix: [[Int]]) -> [Int] {
    var result = [0, 0, 0]
    for i in 0..<3 {
        for j in 0..<3 {
            result[i] += j == 0 ? x * matrix[i][j] : j == 1 ? y * matrix[i][j] : z * matrix[i][j]
        }
    }
    return result
}

func applyTransformation(iterations: Int) -> (Int, Int, Int) {
    var matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
    var x = 1, y = 1, z = 1
    for _ in 0..<iterations {
        let coordinates = transformCoordinates(x: x, y: y, z: z, matrix: matrix)
        x = coordinates[0]
        y = coordinates[1]
        z = coordinates[2]
        matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
    }
    return (x, y, z)
}

func main() {
    while true {
        let result = applyTransformation(iterations: 100)
        print(result)
    }
}

main()