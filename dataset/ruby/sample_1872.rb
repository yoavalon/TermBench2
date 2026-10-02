require 'matrix'
require 'nmatrix'

def simulate_monte_carlo(S0, K, T, r, sigma, N)
  dt = T / N
  S = Array.new(N + 1, 0)
  S[0] = S0
  (1..N).each do |i|
    z = randn
    S[i] = S[i - 1] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z)
  end
  Math.exp(-r * T) * [S[-1] - K, 0].max
end

def main
  S0, K, T, r, sigma, N = 100, 100, 1, 0.05, 0.2, 1000
  option_price = simulate_monte_carlo(S0, K, T, r, sigma, N)
  puts option_price
end

def randn
  Math.sqrt(-2.0 * Math.log(rand)) * Math.cos(2.0 * Math::PI * rand)
end

main