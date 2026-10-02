def optimize
  x, v, p, g = 0, 0, 0, 0
  100.times do
    x = x + v
    v = v + (p - x) + (g - x)
    break if x > 10
  end
  x
end

optimize