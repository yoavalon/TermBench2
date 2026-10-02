require 'numo/narray'

def monte_carlo_pricing(S0, K, T, r, sigma, N, M)
  d1 = (Math.log(S0.to_f / K) + (r + 0.5 * sigma ** 2) * T) / (sigma * Math.sqrt(T))
  d2 = d1 - sigma * Math.sqrt(T)
  call_price = S0 * Math.exp(-r * T) * cdf(d1) - K * Math.exp(-r * T) * cdf(d2)
  return call_price
end

def cdf(x)
  (1.0 + Math.erf(x / Math.sqrt(2.0))) / 2.0
end

if __FILE__ == $0
  result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 1000, 100000)
  puts result
end