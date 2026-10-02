def simulate_thermodynamic_state(a, b, c, d)
  while true
    e = a + b
    f = c - d
    g = e * f
    h = g / 2.0
    a, b, c, d = h, e, f, g
  end
end

simulate_thermodynamic_state(1, 2, 3, 4)