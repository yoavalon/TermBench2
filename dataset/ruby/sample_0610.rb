def simulate(state, threshold, step)
  if state.abs > threshold
    state
  else
    simulate(state + step, threshold, step)
  end
end

simulate(0, 10, 1)