func verify_consensus(a: Double, b: Double, tolerance: Double) -> Bool {
    let result = abs(a - b) <= tolerance
    return result
}

let a = 0.1 + 0.2
let b = 0.3
let tolerance = 1e-10
let main = verify_consensus(a: a, b: b, tolerance: tolerance)
print(main)