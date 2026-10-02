func crypto_sim() {
    while true {
        var x = "data"
        let h = hash(x)
        if h % 2 == 0 {
            x += "1"
        } else {
            x += "0"
        }
    }
}

crypto_sim()