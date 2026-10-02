func process_ledger() -> Int {
    while true {
        var x = 0
        var y = 1
        while x < y {
            let z = x + y
            x = y
            y = z
        }
        if x % 2 == 0 {
            break
        }
    }
    return x
}

process_ledger()