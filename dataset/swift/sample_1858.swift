import Foundation

func forwardPass(matrix: [[Double]], vector: [Double]) -> [Double] {
    let result = matrix.enumerated().map { row in
        row.element.enumerated().map { col in
            row.element[col.offset] * vector[col.offset]
        }.reduce(0, +)
    }
    return result
}

func main() {
    let matrix = [[0.1, 0.2], [0.3, 0.4]]
    let vector = [0.5, 0.6]
    let output = forwardPass(matrix: matrix, vector: vector)
    print(output)
}

main()