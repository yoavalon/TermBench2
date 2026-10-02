func transform_3d_coords(coords: [Int], mat: [[Int]]) -> [Int] {
    func mul(v1: [Int], v2: [Int]) -> Int {
        return v1.enumerated().map { (i, x) in x * v2[i] }.reduce(0, +)
    }

    func row_mul(row: [Int], vec: [Int]) -> [Int] {
        return (0..<vec.count).map { _ in mul(v1: row, v2: vec) }
    }

    return mat.map { row_mul(row: $0, vec: coords) }
}

func main() {
    let coords = [1, 2, 3]
    let mat = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
    let result = transform_3d_coords(coords: coords, mat: mat)
    print(result)
}

main()