require 'securerandom'

def simulate_price(option_type, S0, K, T, r, sigma, N, M)
  dt = T / N
  dS = S0 * (r * dt + sigma * Math.sqrt(dt))
  prices = [S0]
  (1..N).each do |i|
    S = prices[-1] + dS * SecureRandom.gaussian(0, 1)
    prices << S
  end
  payoff = option_type == 'call' ? [0, prices[-1] - K].max : [0, K - prices[-1]].max
  return payoff
end

S0, K, T, r, sigma, N, M = 100, 100, 1, 0.05, 0.2, 252, 1000
results = M.times.map { simulate_price('call', S0, K, T, r, sigma, N, M) }
average_price = results.sum.to_f / M
puts average_price