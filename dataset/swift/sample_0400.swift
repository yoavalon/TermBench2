func flightPlanner() {
    var a = 1.0
    var b = 1000.0
    let c = 0.01
    while true {
        let x = (a + b) / 2
        if x * x < c {
            a = x
        } else {
            b = x
        }
    }
}

flightPlanner()