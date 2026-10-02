def optimize
  a, b, c, d = 0, 1, 1, 0
  100.times do
    a, b, c, d = b, c, d, (a + b + c + d) % 256
  end
  return d
end

optimize