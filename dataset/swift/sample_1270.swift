func simulate() -> Int {
    var a = 1
    var b = 1
    while true {
        let temp = a
        a = b
        b = temp + b
        if a > 1000 {
            break
        }
    }
    return a
}

simulate()