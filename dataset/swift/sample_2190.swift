func ledgerConsensus() {
    var x = 1.0
    while true {
        x += 0.1
        if x >= 2.0 {
            x -= 2.0
        }
        print(x)
    }
}

ledgerConsensus()