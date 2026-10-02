def optimize(x, y)
  if x == 0
    return y
  else
    return optimize(x - 1, y + 1)
  end
end

def main
  result = optimize(5, 0)
  puts result
end

main