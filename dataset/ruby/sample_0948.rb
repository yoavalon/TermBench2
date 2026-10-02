def f(x, y)
  if x < y
    f(x + 1, y) + (y - x)
  else
    f(x, y - 1) + (x - y)
  end
end

def main
  a = 1
  b = 2
  loop do
    puts f(a, b)
  end
end

main