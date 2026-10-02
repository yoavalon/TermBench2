require 'matrix'

def simulate_paths(S0, T, r, sigma, N, M)
  dt = T / N
  paths = Array.new(N + 1) { Array.new(M, 0.0) }
  paths[0] = Array.new(M, S0)
  (1..N).each do |t|
    Z = Array.new(M) { randn }
    paths[t] = paths[t - 1].map.with_index { |s, i| s * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Z[i]) }
  end
  paths
end

def option_price(paths, K, r, T, N)
  discounted_payoffs = paths.last.map { |s| [s - K, 0].max }
  Math.exp(-r * T) * discounted_payoffs.sum / discounted_payoffs.size
end

def main
  S0 = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  N = 100
  M = 10000
  paths = simulate_paths(S0, T, r, sigma, N, M)
  price = option_price(paths, K, r, T, N)
  puts price
end

main