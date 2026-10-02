require 'matrix'

def monte_carlo_option_pricing(S0, K, T, r, sigma, N)
  dt = T / N
  S = Array.new(N + 1, 0)
  S[0] = S0
  (1..N).each do |i|
    S[i] = S[i - 1] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * randn)
  end
  payoff = [S[-1] - K, 0].max
  option_price = Math.exp(-r * T) * payoff
  return option_price
end

def randn
  Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
end

if __FILE__ == $0
  result = monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 1000)
  puts result
end