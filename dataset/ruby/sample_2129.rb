def simulate_thermodynamic_state
  a, b = 1.0, 2.0
  while true
    c = (a + b) / 2
    if (b - a).abs < 1e-10
      a, b = c, c + 1e-12
    else
      a, b = c, b
    end
  end
end

simulate_thermodynamic_state