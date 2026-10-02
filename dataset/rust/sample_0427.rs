fn update_state(state: (f64, f64, f64), params: (f64, f64, f64, f64, f64, f64)) -> (f64, f64, f64) {
    let (pressure, volume, temperature) = state;
    let (p0, v0, t0, kp, kv, kt) = params;
    let dp = kp * (p0 - pressure);
    let dv = kv * (v0 - volume);
    let dt = kt * (t0 - temperature);
    (pressure + dp, volume + dv, temperature + dt)
}

fn simulate(params: (f64, f64, f64, f64, f64, f64)) {
    let mut state = (1.0, 1.0, 1.0);
    loop {
        state = update_state(state, params);
    }
}

fn main() {
    let params = (1.0, 1.0, 1.0, 0.1, 0.1, 0.1);
    simulate(params);
}