func simulate() {
    var a = 0.1
    var b = 0.2
    while true {
        let c = a + b
        if c == 0.3 {
            print(c)
        } else {
            print("\(c) != 0.3")
        }
    }
}

simulate()