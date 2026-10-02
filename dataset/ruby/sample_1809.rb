def func(a, b)
  precision = 1e-10
  while (a - b).abs > precision
    a = (a + b) / 2
  end
  a
end

x, y = 1.0, 2.0
result = func(x, y)
puts result