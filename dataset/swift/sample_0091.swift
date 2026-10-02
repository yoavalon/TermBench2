func consensus_mechanism() -> Int {
    var a = 1
    var b = 0
    for _ in 0..<10 {
        let temp = a
        a = b
        b = temp + b
    }
    return a
}

consensus_mechanism()