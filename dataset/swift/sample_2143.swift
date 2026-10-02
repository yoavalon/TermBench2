func flightAltitudePlanning() {
    var a = 36000.0
    var b = 10.0
    var c = 0.001
    var i = 0
    while true {
        a += b * c
        b -= c
        c *= 2
        i += 1
        if i % 1000 == 0 {
            print(a, b, c)
        }
    }
}

flightAltitudePlanning()