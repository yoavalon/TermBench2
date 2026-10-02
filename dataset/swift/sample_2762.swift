func flightPlanner() {
    var a = 10000
    var b = 20000
    while true {
        print("Cruise Altitude: \(a)m")
        (a, b) = (b, a + 500)
    }
}

flightPlanner()