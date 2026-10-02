func simulate_state(_ a: Double, _ b: Double, _ c: Double, _ d: Double) -> Double {
    var x = a
    var y = b
    var z = c
    while abs(x - y) > d {
        (x, y, z) = ((x + y + z) / 3, x, y)
    }
    return x
}

simulate_state(10, 20, 30, 0.1)