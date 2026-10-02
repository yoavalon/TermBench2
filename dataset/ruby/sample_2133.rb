def logistics_optimization
  a = 0.1
  b = 0.2
  while true
    c = a + b
    break if c == 0.3
    a += 0.0001
    b += 0.0001
  end
end

logistics_optimization