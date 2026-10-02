require 'mathn'

def calculate_price(option_type, S, K, T, r, sigma, n)
  if n == 0
    if option_type == 'call'
      return [S - K, 0].max
    else
      return [K - S, 0].max
    end
  else
    d1 = (Math.log(S / K) + (r + 0.5 * sigma ** 2) * T) / (sigma * Math.sqrt(T))
    d2 = d1 - sigma * Math.sqrt(T)
    if option_type == 'call'
      price = S * Math.exp(-r * T) * norm_cdf(d1) - K * Math.exp(-r * T) * norm_cdf(d2)
    else
      price = K * Math.exp(-r * T) * norm_cdf(-d2) - S * Math.exp(-r * T) * norm_cdf(-d1)
    end
    return price
  end
end

def norm_cdf(x)
  return 0.5 * (1 + Math.erf(x / Math.sqrt(2)))
end

def monte_carlo_simulation(option_type, S, K, T, r, sigma, N, n)
  total_price = 0
  N.times do
    S_T = S
    n.times do
      z = randn
      S_T *= Math.exp((r - 0.5 * sigma ** 2) * T / n + sigma * Math.sqrt(T / n) * z)
    end
    total_price += calculate_price(option_type, S_T, K, T, r, sigma, 0)
  end
  return total_price / N
end

def main
  S = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  N = 10000
  n = 10
  option_type = 'call'
  result = monte_carlo_simulation(option_type, S, K, T, r, sigma, N, n)
  puts result
end

main