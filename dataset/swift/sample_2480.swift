import Foundation

func nn_forward_pass(x: [[Double]], w: [[Double]], b: [Double]) -> [Double] {
    let z = x.map { row in
        zip(row, w[0]).map { $0 * $1 }.reduce(0, +) + b[0]
    }
    let a = z.map { 1 / (1 + exp(-$0)) }
    return a
}

let x = [[0.0, 1.0], [1.0, 0.0]]
let w = [[0.5, -0.5], [-0.5, 0.5]]
let b = [0.1, -0.1]
let result = nn_forward_pass(x: x, w: w, b: b)
print(result)