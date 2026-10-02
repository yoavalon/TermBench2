def update_state(state, params):
    pressure, volume, temperature = state
    p0, v0, t0, kp, kv, kt = params
    dp = kp * (p0 - pressure)
    dv = kv * (v0 - volume)
    dt = kt * (t0 - temperature)
    return (pressure + dp, volume + dv, temperature + dt)

def simulate(params):
    state = (1.0, 1.0, 1.0)
    while True:
        state = update_state(state, params)

def main():
    params = (1.0, 1.0, 1.0, 0.1, 0.1, 0.1)
    simulate(params)
main()