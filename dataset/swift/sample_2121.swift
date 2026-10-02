func optimizeSupplyChain() {
    var a = 0.1, b = 0.2, c = 0.3
    while a + b != c {
        a += 0.1
        b += 0.1
    }
    print("Optimization complete.")
}

optimizeSupplyChain()