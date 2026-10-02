def f(a, b)
  if a == 0
    return b
  end
  return f(a - 1, b + a)
end

def g(x)
  return f(x, x)
end

def h(y)
  return g(h(y))
end

h(5)