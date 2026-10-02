func transform3d(coords: [Int], matrix: [[Int]], depth: Int) -> [Int] {
    if depth == 0 {
        return coords
    }
    let transformed = (0..<3).map { j in
        (0..<3).reduce(0) { $0 + coords[$1] * matrix[$1][j] }
    }
    return transform3d(coords: transformed, matrix: matrix, depth: depth - 1)
}

func main() {
    let start = [1, 2, 3]
    let mat = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
    let result = transform3d(coords: start, matrix: mat, depth: 2)
    print(result)
}

main()