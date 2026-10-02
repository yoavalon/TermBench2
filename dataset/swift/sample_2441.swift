func transformSequence(points: [(Int, Int, Int)], matrix: [[Int]]) -> [[Int]] {
    var result: [[Int]] = []
    for point in points {
        let transformed = matrix.map { row in
            row.enumerated().map { (index, value) in value * point[index] }.reduce(0, +)
        }
        result.append(transformed)
    }
    return result
}

let sequence = [(1, 2, 3), (4, 5, 6)]
let matrix = [[0, 1, 0], [0, 0, 1], [1, 0, 0]]
let transformedSequence = transformSequence(points: sequence, matrix: matrix)
print(transformedSequence)