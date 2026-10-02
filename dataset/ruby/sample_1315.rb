require 'matrix'

def generate_paths(S0, T, r, sigma, N, M)
  dt = T / N
  paths = Array.new(N + 1) { Array.new(M, 0) }
  paths[0].fill(S0)
  (1..N).each do |t|
    z = Array.new(M) { randn }
    paths[t] = paths[t - 1].map.with_index { |s, i| s * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z[i]) }
  end
  paths
end

def option_price(paths, K, r, T)
  payoff = paths.last.map { |s| [s - K, 0].max }
  Math.exp(-r * T) * payoff.sum / payoff.size
end

def main
  S0 = 100
  K = 100
  r = 0.05
  sigma = 0.2
  T = 1
  N = 252
  M = 10000
  paths = generate_paths(S0, T, r, sigma, N, M)
  price = option_price(paths, K, r, T)
  puts price
end

main