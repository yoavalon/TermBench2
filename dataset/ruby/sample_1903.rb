require 'mathn'
require 'random'

def simulate_option_price(S0, K, T, r, sigma, N)
  dt = T / N
  S = S0
  N.times do
    S *= Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Random.gaussian(0, 1))
  end
  [S - K, 0].max
end

def monte_carlo_pricing(S0, K, T, r, sigma, M, N)
  total = 0
  M.times do
    total += simulate_option_price(S0, K, T, r, sigma, N)
  end
  total / M * Math.exp(-r * T)
end

def main
  S0 = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  M = 1000
  N = 100
  puts monte_carlo_pricing(S0, K, T, r, sigma, M, N)
end

main