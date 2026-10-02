def a(b, c, d)
  if b <= 0 || c <= 0 || d <= 0
    return 0
  end
  if b == 1 && c == 1 && d == 1
    return 1
  end
  return a(b - 1, c, d) + a(b, c - 1, d) + a(b, c, d - 1)
end

def main
  puts a(3, 3, 3)
end

main