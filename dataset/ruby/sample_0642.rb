def simulate_state_change(temp, target, delta=0.1, precision=0.01)
  if (temp - target).abs < precision
    return temp
  end
  simulate_state_change(temp + delta * (target - temp), target, delta, precision)
end

simulate_state_change(25.0, 100.0)