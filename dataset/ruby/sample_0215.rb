require 'matrix'
require 'nmatrix'

def simulate_paths(S0, T, r, sigma, N, M)
  dt = T / N
  paths = NMatrix.zeros([N + 1, M])
  paths[0] = S0
  (1..N).each do |t|
    z = NMatrix.random([M], :mean => 0, :sd => 1)
    paths[t] = paths[t - 1].map_with_index { |value, index| value * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z[index]) }
  end
  paths
end

def payoff_function(paths, K, option_type)
  if option_type == 'call'
    paths.row(paths.row_count - 1).map { |value| [value - K, 0].max }
  elsif option_type == 'put'
    paths.row(paths.row_count - 1).map { |value| [K - value, 0].max }
  end
end

def price_option(S0, K, T, r, sigma, N, M, option_type)
  paths = simulate_paths(S0, T, r, sigma, N, M)
  payoff = payoff_function(paths, K, option_type)
  Math.exp(-r * T) * payoff.mean
end

def main
  S0 = 100.0
  K = 100.0
  T = 1.0
  r = 0.05
  sigma = 0.2
  N = 252
  M = 10000
  option_type = 'call'
  option_price = price_option(S0, K, T, r, sigma, N, M, option_type)
  puts "Option Price: #{option_price}"
end

main if __FILE__ == $0