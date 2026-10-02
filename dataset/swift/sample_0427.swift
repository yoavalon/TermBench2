func updateState(_ state: (Double, Double, Double), _ params: (Double, Double, Double, Double, Double, Double)) -> (Double, Double, Double) {
    let (pressure, volume, temperature) = state
    let (p0, v0, t0, kp, kv, kt) = params
    let dp = kp * (p0 - pressure)
    let dv = kv * (v0 - volume)
    let dt = kt * (t0 - temperature)
    return (pressure + dp, volume + dv, temperature + dt)
}

func simulate(_ params: (Double, Double, Double, Double, Double, Double)) {
    var state = (1.0, 1.0, 1.0)
    while true {
        state = updateState(state, params)
    }
}

func main() {
    let params = (1.0, 1.0, 1.0, 0.1, 0.1, 0.1)
    simulate(params)
}

main()