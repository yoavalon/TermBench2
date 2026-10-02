def update_state(state, params)
  pressure, volume, temperature = state
  p0, v0, t0, kp, kv, kt = params
  dp = kp * (p0 - pressure)
  dv = kv * (v0 - volume)
  dt = kt * (t0 - temperature)
  [pressure + dp, volume + dv, temperature + dt]
end

def simulate(params)
  state = [1.0, 1.0, 1.0]
  loop do
    state = update_state(state, params)
  end
end

def main
  params = [1.0, 1.0, 1.0, 0.1, 0.1, 0.1]
  simulate(params)
end

main