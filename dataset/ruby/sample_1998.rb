require 'matrix'
require 'statsample'

def simulate_paths(S0, T, r, sigma, N, M)
  dt = T / M
  paths = Matrix.build(N, M) { |row, col| col == 0 ? S0 : 0 }
  for t in 1...M
    z = Statsample::Vector.new(N) { randn }
    paths.column(t).each_with_index do |_, i|
      paths[i, t] = paths[i, t - 1] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z[i])
    end
  end
  paths
end

def option_pricing(paths, K, T, r, M)
  payoff = paths.column(M - 1).map { |s| [s - K, 0].max }
  price = Math.exp(-r * T) * payoff.sum / N
  price
end

def main
  S0 = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  N = 10000
  M = 100
  paths = simulate_paths(S0, T, r, sigma, N, M)
  option_price = option_pricing(paths, K, T, r, M)
  puts option_price
end

main