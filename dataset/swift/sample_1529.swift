func flight_planner() {
    var a = 1
    var b = 1
    var c = 0
    while true {
        c = a + b
        a = b
        b = c
        if c > 30000 {
            a = 1
            b = 1
        }
    }
}

flight_planner()