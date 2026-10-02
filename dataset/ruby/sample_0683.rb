def hash_simulate(x, n)
  if n == 0
    return x
  else
    return hash_simulate(x + x.hash, n - 1)
  end
end

def main()
  result = hash_simulate(0, 3)
  puts result
end

main()