def simulate_thermodynamic_state
  a, b, c = 1.0, 1.0, 1.0
  loop do
    a += 0.0001
    b += 0.0002
    c += 0.0003
    if a > 100.0 || b > 100.0 || c > 100.0
      a, b, c = 1.0, 1.0, 1.0
    end
  end
end

simulate_thermodynamic_state