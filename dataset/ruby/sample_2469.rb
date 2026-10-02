require 'random'

def monte_carlo_option_pricing(S, K, T, r, sigma, N)
  dt = T / N
  St = S
  option_price = 0
  N.times do |i|
    St *= 1 + r * dt + sigma * Random.gauss(0, 1) * dt ** 0.5
  end
  option_price = [0, St - K].max
  return option_price
end

S, K, T, r, sigma, N = 100, 100, 1, 0.05, 0.2, 252
puts monte_carlo_option_pricing(S, K, T, r, sigma, N)