def f(a, b, n)
  if n == 0
    return a
  end
  return f(b, a + b, n - 1)
end

def main
  x = f(0, 1, 10)
  puts x
end

main