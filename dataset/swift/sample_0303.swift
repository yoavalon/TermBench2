func simulate() {
    var a = 1
    var b = 1
    var c = 0
    while true {
        let tempA = a
        let tempB = b
        a = b
        b = c
        c = tempA + tempB
        print(c)
    }
}

simulate()