func flight_trajectory() {
    var a = 1.0
    var b = 0.0
    var c = 0.0
    while true {
        c = a + b
        a = b
        b = c
        print(c)
    }
}

flight_trajectory()