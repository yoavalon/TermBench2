require 'random'

def simulate_paths(S0, mu, sigma, T, N, M)
  dt = T / N
  paths = Array.new(M) { [S0] }
  (1..N).each do |_|
    (0...M).each do |j|
      dW = Random.gaussian(0, 1) * dt ** 0.5
      paths[j] << paths[j][-1] * (1 + mu * dt + sigma * dW)
    end
  end
  paths
end

def option_price(paths, K, r, T)
  payoff = paths.map { |path| [path.last - K, 0].max }
  discounted_payoff = payoff.map { |p| p * (1 - r * T) }
  discounted_payoff.sum / discounted_payoff.size
end

def main
  S0, K, T, r, sigma = 100, 100, 1, 0.05, 0.2
  N, M = 100, 1000
  paths = simulate_paths(S0, mu: r, sigma: sigma, T: T, N: N, M: M)
  price = option_price(paths, K, r, T)
  puts price
end

main