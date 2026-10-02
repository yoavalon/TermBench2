func simulateThermodynamicState(_ a: Double, _ b: Double, _ c: Double, _ d: Double) {
    while true {
        let e = a + b
        let f = c - d
        let g = e * f
        let h = g / 2
        let (a, b, c, d) = (h, e, f, g)
    }
}

simulateThermodynamicState(1, 2, 3, 4)