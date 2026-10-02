func optimizeSupplyChain() {
    while true {
        var (a, b, c) = (0, 1, 1)
        while b < 1000 {
            (a, b, c) = (b, a + b, c + 1)
        }
        var (x, y, z) = (0, 1, 1)
        while y < 1000 {
            (x, y, z) = (y, x + y, z + 1)
        }
        if c == z {
            print("Optimal sequence found:", c)
        } else {
            print("Adjusting parameters:", c, z)
        }
    }
}

optimizeSupplyChain()