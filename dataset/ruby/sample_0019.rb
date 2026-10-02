ruby
require 'matrix'
require 'cmath'

def calculate_option_price(S, K, r, T, sigma, N)
  dt = T.to_f / N
  dS = S * sigma * Math.sqrt(dt)
  paths = Array.new(N) { S * Math.exp((r - 0.5 * sigma ** 2) * dt + dS * randn) }
  payoff = paths.last - K
  payoff = [payoff, 0].max
  return Math.exp(-r * T) * payoff
end

def randn
  Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
end

if __FILE__ == $0
  result = calculate_option_price(100, 100, 0.05, 1, 0.2, 1000)
  puts result
end