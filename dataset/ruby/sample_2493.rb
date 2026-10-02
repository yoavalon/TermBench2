def f(a, b, c)
  if a > b
    return c
  else
    return f(a + 1, b, c + 1)
  end
end

def main
  result = f(1, 10, 0)
  puts result
end

main