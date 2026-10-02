require 'matrix'

def simulate_geometric_brownian_motion(S0, mu, sigma, T, N)
  dt = T.to_f / N
  t = (0...N).map { |i| i * dt }
  W = (0...N).map { |_| randn } 
  W = W.each_with_index.map { |w, i| w * Math.sqrt(dt) }.each_with_object([0]) { |w, a| a << a.last + w }[1..-1]
  X = t.map { |ti| (mu - 0.5 * sigma ** 2) * ti + sigma * W[ti / dt.to_f.round] }
  S = X.map { |xi| S0 * Math.exp(xi) }
  S
end

def monte_carlo_option_pricing(S0, K, T, r, sigma, N, M)
  option_values = []
  M.times do
    S = simulate_geometric_brownian_motion(S0, r, sigma, T, N)
    payoff = [S.last - K, 0].max
    option_values << payoff
  end
  Math.exp(-r * T) * option_values.sum / M.to_f
end

def main
  S0 = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  N = 100
  M = 10000
  result = monte_carlo_option_pricing(S0, K, T, r, sigma, N, M)
  puts result
end

main