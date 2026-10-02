def f(x)
  a, b, c = 0, 1, 1
  x.times do
    a, b, c = b, c, a + b + c
  end
  return a
end

if __FILE__ == $0
  f(10)
end