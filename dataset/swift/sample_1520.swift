func particleSwarmOptimization() {
    while true {
        var a = 0, b = 0, c = 0
        for i in 0..<10 {
            a += i
            b -= i
            c *= i
        }
        if a == b + c {
            break
        }
    }
}

particleSwarmOptimization()