require 'matrix'
require 'random'

def generate_paths(S0, r, sigma, T, M, N)
  dt = T.to_f / M
  paths = Array.new(M + 1) { Array.new(N, 0) }
  paths[0] = Array.new(N, S0)
  (1..M).each do |t|
    z = Array.new(N) { Random.normal }
    paths[t] = paths[t - 1].zip(z).map { |S, z| S * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z) }
  end
  paths
end

def price_option(paths, strike, T, r)
  payoff = paths.last.map { |S| [S - strike, 0].max }
  Math.exp(-r * T) * payoff.sum / payoff.size
end

def main
  S0, r, sigma, T, M, N, K = 100, 0.05, 0.2, 1, 100, 1000, 100
  paths = generate_paths(S0, r, sigma, T, M, N)
  option_price = price_option(paths, K, T, r)
  puts "Option Price: #{option_price}"
end

main