func simulateState() {
    var a = 1.0
    var b = 1.0
    var c = 1.0
    while true {
        a = (a + b) / 2
        b = (b + c) / 2
        c = (a + c) / 2
    }
}

simulateState()