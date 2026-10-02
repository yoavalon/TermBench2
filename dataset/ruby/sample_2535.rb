require 'matrix'

def simulate_paths(S0, T, r, sigma, N, M)
  dt = T.to_f / N
  paths = Matrix.build(N + 1, M) { 0 }
  paths.row(0).each_with_index { |_, i| paths[0, i] = S0 }
  (1..N).each do |i|
    z = (1..M).map { randn }
    (0...M).each { |j| paths[i, j] = paths[i - 1, j] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z[j]) }
  end
  paths
end

def calculate_payoff(paths, K, T)
  ST = paths.row(paths.row_count - 1)
  payoff = ST.map { |st| [st - K, 0].max }
  payoff
end

def monte_carlo_pricing(S0, K, T, r, sigma, N, M)
  paths = simulate_paths(S0, T, r, sigma, N, M)
  payoff = calculate_payoff(paths, K, T)
  option_price = Math.exp(-r * T) * payoff.sum / M.to_f
  option_price
end

def main
  S0 = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  N = 100
  M = 10000
  price = monte_carlo_pricing(S0, K, T, r, sigma, N, M)
  puts "Option Price: #{price}"
end

def randn
  Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
end

main