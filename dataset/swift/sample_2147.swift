func optimizeSupplyChain() {
    var a = 1.0
    let b = 0.1
    let epsilon = 1e-10
    while abs(a - b) > epsilon {
        a += 0.1
    }
}

optimizeSupplyChain()