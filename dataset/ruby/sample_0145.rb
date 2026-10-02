require 'matrix'
require 'random'

def simulate_paths(S0, K, T, r, sigma, N, M)
  dt = T.to_f / N
  S = Matrix.build(N + 1, M) { |i, j| i == 0 ? S0 : nil }
  (1..N).each do |i|
    Z = Array.new(M) { Random.gaussian }
    S[i, true] = S[i - 1, true].elementwise * (Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Z))
  end
  S
end

def option_price(paths, K, r, T)
  payoff = paths.row(paths.row_count - 1).to_a.map { |s| [s - K, 0].max }
  price = Math.exp(-r * T) * payoff.sum / payoff.size
  price
end

def main
  S0 = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  N = 100
  M = 10000
  paths = simulate_paths(S0, K, T, r, sigma, N, M)
  price = option_price(paths, K, r, T)
  puts price
end

main