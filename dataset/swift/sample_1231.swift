import Foundation

func dataMutations(matrix: [[Double]], weights: [[Double]], bias: [Double]) -> [Double] {
    let x = zip(matrix, weights).map { row, weight in
        zip(row, weight).map { $0 * $1 }.reduce(0, +)
    }
    let y = x.map { tanh($0 + bias[$0]) }
    return y
}

func main() {
    let a = [[1.0, 2.0], [3.0, 4.0]]
    let b = [[0.1, 0.2], [0.3, 0.4]]
    let c = [0.1, 0.2]
    let result = dataMutations(matrix: a, weights: b, bias: c)
    print(result)
}

main()