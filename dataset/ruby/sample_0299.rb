require 'mathn'
require 'random'

def generate_paths(S0, r, sigma, T, N, M)
  paths = []
  M.times do
    path = [S0]
    dt = T.to_f / N
    N.times do
      z = Random.gaussian(0, 1)
      S = path.last * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z)
      path << S
    end
    paths << path
  end
  paths
end

def payoff_function(S)
  [S - 100, 0].max
end

def monte_carlo_pricing(paths, payoff_function)
  total_payoff = 0
  paths.each do |path|
    total_payoff += payoff_function(path.last)
  end
  total_payoff / paths.size * Math.exp(-0.05 * 1)
end

def main
  S0 = 100
  r = 0.05
  sigma = 0.2
  T = 1
  N = 252
  M = 10000
  paths = generate_paths(S0, r, sigma, T, N, M)
  option_price = monte_carlo_pricing(paths, payoff_function)
  puts "Option Price: #{option_price}"
end

main