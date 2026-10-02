require 'numo/narray'

def monte_carlo_pricing(S, K, T, r, sigma, N)
  dt = T / N
  S_t = Numo::DFloat.zeros(N + 1)
  S_t[0] = S
  z = Numo::DFloat.random_normal(N)
  (1..N).each do |i|
    S_t[i] = S_t[i - 1] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z[i - 1])
  end
  payoff = Numo::DFloat[max(S_t[-1] - K, 0)]
  option_price = Math.exp(-r * T) * payoff.mean
  return option_price
end

if __FILE__ == $0
  result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000)
  puts result
end