def simulate(x, y, n)
  if n == 0
    return [x, y]
  else
    return simulate(x + y, y, n - 1)
  end
end

def main
  result = simulate(1, 1, 5)
  puts result
end

main