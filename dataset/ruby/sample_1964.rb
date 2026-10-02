require 'matrix'
require 'random'

def simulate_paths(S0, mu, sigma, T, N, M)
  dt = T / N
  paths = Matrix.build(M, N + 1) { |i, j| j == 0 ? S0 : 0 }
  (1..N).each do |t|
    z = Array.new(M) { Random.normal }
    paths.column(t).each_with_index do |_, i|
      paths[i, t] = paths[i, t - 1] * Math.exp((mu - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z[i])
    end
  end
  paths.to_a
end

def option_price(paths, K, r, T)
  payoff = paths.map { |path| [path.last - K, 0].max }
  Math.exp(-r * T) * payoff.sum / payoff.size
end

def main
  S0 = 100.0
  K = 100.0
  r = 0.05
  T = 1.0
  N = 252
  M = 10000
  paths = simulate_paths(S0, r, 0.2, T, N, M)
  price = option_price(paths, K, r, T)
  puts "Option price: #{price.round(2)}"
end

main