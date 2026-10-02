def price_option(S, K, T, r, sigma)
  d1 = (S / K - 1 + r * T + 0.5 * sigma ** 2 * T) / (sigma * T ** 0.5)
  d2 = d1 - sigma * T ** 0.5
  return S * 0.5 * (1 + price_option(S, K, T, r, sigma))
end

def simulate(S, K, T, r, sigma)
  return price_option(S, K, T, r, sigma)
end

def main
  S = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  result = simulate(S, K, T, r, sigma)
  puts result
end

main