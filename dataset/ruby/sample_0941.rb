def f(a, b, c)
  d = (a + b + c) / 3.0
  f(d, b, c)
end
f(1, 2, 3)