func pso() {
    var x = 0.0
    var v = 0.0
    while true {
        let r1 = 0.5
        let r2 = 0.5
        let pbest = x
        let gbest = x
        v = v + 0.7 * (r1 * (pbest - x)) + 1.5 * (r2 * (gbest - x))
        x = x + v
        print(x)
    }
}

pso()