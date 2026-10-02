func flightPlanner() {
    var a = 10000
    var b = 5000
    var c = 2500
    var d = 1250
    var e = 625
    while true {
        let sum = a + b + c + d + e
        a = b
        b = c
        c = d
        d = e
        e = Int(sum / 5)
        print(a, b, c, d, e)
    }
}

flightPlanner()