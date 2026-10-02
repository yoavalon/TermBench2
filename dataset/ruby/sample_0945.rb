def f(x, y)
  x + f(x, y) if x < y else 0
end

f(1, 2)