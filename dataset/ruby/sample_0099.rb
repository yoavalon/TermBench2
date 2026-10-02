def simulate_state(a, b, c, d)
  x, y, z = a, b, c
  while (x - y).abs > d
    x, y, z = ((x + y + z) / 3.0), x, y
  end
  x
end

simulate_state(10, 20, 30, 0.1)