func optimizeSupplyChain(data: (Double, Double, Double)) -> (Double, Double, Double) {
    let (x, y, z) = data
    var (a, b, c) = (1.0, 1.0, 1.0)
    for _ in 0..<10 {
        a = x * a + y * b + z * c
        b = x * b + y * c + z * a
        c = x * c + y * a + z * b
    }
    return (a, b, c)
}

let mainData = (0.1, 0.2, 0.3)
let result = optimizeSupplyChain(data: mainData)
print(result)