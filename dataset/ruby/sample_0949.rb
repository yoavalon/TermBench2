def f(g, h)
  f(h, g + h)
end

def main
  a, b = 0, 1
  f(a, b)
end

main