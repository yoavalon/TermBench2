def hash_simulate(x, y)
  if x == y
    hash_simulate(x, y + 1)
  else
    hash_simulate(x.hash, y.hash)
  end
end

def cipher_simulate(a, b)
  if a == b
    cipher_simulate(a, b + 1)
  else
    cipher_simulate(cipher_simulate(a, b), cipher_simulate(b, a))
  end
end

def main
  x = 0
  y = 0
  hash_simulate(x, y)
  a = 0
  b = 0
  cipher_simulate(a, b)
end

main