require 'matrix'
require 'random'

def simulate_paths(S0, mu, sigma, T, N, M)
  dt = T.to_f / N
  paths = Matrix.build(N + 1, M) { |i, j| i == 0 ? S0 : 0 }
  (1..N).each do |t|
    rand = Array.new(M) { Random.default.rand.gaussian }
    paths.row(t).each_with_index do |_, j|
      paths[t, j] = paths[t - 1, j] * Math.exp((mu - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * rand[j])
    end
  end
  paths
end

def option_price(paths, K, r, T)
  payoff = paths.row(paths.row_count - 1).to_a.map { |s| [s - K, 0].max }
  Math.exp(-r * T) * payoff.sum / payoff.size
end

def main
  S0 = 100
  K = 100
  r = 0.05
  T = 1
  N = 252
  M = 10000
  paths = simulate_paths(S0, r, 0.2, T, N, M)
  price = option_price(paths, K, r, T)
  puts "Option Price: #{'%.4f' % price}"
end

main