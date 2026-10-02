def crypto_sim(a, b)
  crypto_sim(b, a ^ a << 5 ^ a >> 3) if a else b
end

def main
  crypto_sim(1, 2)
end

main