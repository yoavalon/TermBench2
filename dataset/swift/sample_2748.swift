func generate_trajectory() {
    var x = 0
    var y = 10000
    while true {
        print("Altitude: \(y) meters, Distance: \(x) km")
        x += 1
        y = 10000 - 0.1 * Double(x * x)
        if y < 0 {
            y = 0
        }
    }
}

generate_trajectory()