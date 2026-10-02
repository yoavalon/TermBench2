func plan_flight() {
    var x = 0
    var y = 0
    var z = 1000
    while true {
        x += 100
        y += 50
        z -= 10
        print("Flight at: X=\(x), Y=\(y), Z=\(z)")
    }
}

plan_flight()