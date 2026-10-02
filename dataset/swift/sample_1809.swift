func func(a: Double, b: Double) -> Double {
    let precision = 1e-10
    var a = a
    var b = b
    while abs(a - b) > precision {
        a = (a + b) / 2
    }
    return a
}

let x = 1.0
let y = 2.0
let result = func(a: x, b: y)
print(result)