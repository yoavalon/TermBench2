require 'matrix'
require 'cmath'

def monte_carlo_option_pricing(S, K, T, r, sigma, N)
  dt = T / N
  S_T = S * (1 + (r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Matrix.build(N) { randn })
  return Math.exp(-r * T) * S_T.diagonal.to_a.map { |x| [x - K, 0].max }.sum / N
end

def randn
  Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
end

if __FILE__ == $0
  result = monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 10000)
  puts result
end