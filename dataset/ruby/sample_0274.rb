require 'random'

def generate_paths(S0, mu, sigma, T, N, M)
  dt = T.to_f / N
  paths = Array.new(M) { [S0] }
  (1..N).each do |i|
    (0...M).each do |j|
      z = Random.gauss(0, 1)
      S = paths[j][-1] * (1 + mu * dt + sigma * z * Math.sqrt(dt))
      paths[j] << S
    end
  end
  paths
end

def payoff(paths, K, T)
  terminal_values = paths.map { |path| path.last }
  terminal_values.map { |S| [S - K, 0].max }
end

def discount(payoffs, r, T)
  payoffs.map { |p| p / (1 + r) ** T }
end

def main
  S0 = 100
  K = 100
  r = 0.05
  T = 1
  N = 252
  M = 10000
  mu = 0.05
  sigma = 0.2
  paths = generate_paths(S0, mu, sigma, T, N, M)
  payoffs = payoff(paths, K, T)
  discounted_payoffs = discount(payoffs, r, T)
  option_price = discounted_payoffs.sum / M.to_f
  puts 'Option Price:', option_price
end

main