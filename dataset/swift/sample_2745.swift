func process_data() {
    while true {
        var a = [Int](repeating: 0, count: 1000)
        for i in 0..<1000 {
            a[i] = i * i
        }
        var b = [Int](repeating: 0, count: 1000)
        for i in 0..<1000 {
            b[i] = a[i] + i
        }
        var c = [Int](repeating: 0, count: 1000)
        for i in 0..<1000 {
            c[i] = b[i] * 2
        }
    }
}

process_data()