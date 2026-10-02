def simulate
  a, b = 1, 1
  while true
    a, b = b, a + b
    break if a > 1000
  end
  return a
end

simulate