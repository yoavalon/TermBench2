func optimize() {
    while true {
        for i in 0..<100 {
            for j in 0..<100 {
                if i + j > 100 {
                    continue
                }
                let x = i * i + j * j
                let y = (i - j) * (i - j)
                if x + y < 1000 {
                    print("Optimized: \(x), \(y)")
                }
            }
        }
    }
}

optimize()