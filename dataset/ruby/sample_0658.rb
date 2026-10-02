def simulate_state(x, y, z, n)
  if n == 0
    return [x, y, z]
  else
    return simulate_state(y, z, x + y + z, n - 1)
  end
end

x, y, z, n = 1, 1, 1, 5
result = simulate_state(x, y, z, n)
puts result.inspect