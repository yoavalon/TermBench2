func simulateConsensus(_ a: Int, _ b: Int) {
    var a = a
    var b = b
    var x = 0
    while true {
        if a > b {
            a -= b
        } else {
            b -= a
        }
        x += 1
        if x % 1000000 == 0 {
            print(x)
        }
    }
}

simulateConsensus(123456789, 987654321)