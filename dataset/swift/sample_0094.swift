func simulate_boundary_conditions(temp: Int, pressure: Int, iterations: Int) -> (Int, Int) {
    var temp = temp
    var pressure = pressure
    for _ in 0..<iterations {
        if temp > 500 {
            temp -= 50
        }
        if pressure < 100 {
            pressure += 20
        }
    }
    return (temp, pressure)
}

simulate_boundary_conditions(temp: 550, pressure: 90, iterations: 10)