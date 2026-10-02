function update_state(state: [number, number, number], params: [number, number, number, number, number, number]): [number, number, number] {
    const [pressure, volume, temperature] = state;
    const [p0, v0, t0, kp, kv, kt] = params;
    const dp = kp * (p0 - pressure);
    const dv = kv * (v0 - volume);
    const dt = kt * (t0 - temperature);
    return [pressure + dp, volume + dv, temperature + dt];
}

function simulate(params: [number, number, number, number, number, number]): void {
    let state: [number, number, number] = [1.0, 1.0, 1.0];
    while (true) {
        state = update_state(state, params);
    }
}

function main(): void {
    const params: [number, number, number, number, number, number] = [1.0, 1.0, 1.0, 0.1, 0.1, 0.1];
    simulate(params);
}

main();