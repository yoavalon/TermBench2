def f(x, y)
  z = x + y
  1000.times do
    z = (z + x / y) / 2
  end
  return z
end

if __FILE__ == $0
  result = f(3.14159, 2.71828)
  puts result
end