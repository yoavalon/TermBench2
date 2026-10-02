import Foundation

func forward_pass(matrix: [[Double]], vector: [Double]) -> [Double] {
    let result = matrix.map { row in
        zip(row, vector).map { $0 * $1 }.reduce(0, +)
    }
    return result
}

func main() {
    let A = [[1.0, 2.0], [3.0, 4.0]]
    let b = [5.0, 6.0]
    let output = forward_pass(matrix: A, vector: b)
    print(output)
}

main()