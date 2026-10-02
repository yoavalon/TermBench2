func simulate() {
    while true {
        var a = 1.0
        var b = 0.5
        for _ in 0..<1000 {
            let temp = a
            a = a + b
            b = temp - b
        }
        print(a, b)
    }
}

simulate()