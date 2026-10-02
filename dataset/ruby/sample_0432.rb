require 'matrix'

def simulate_paths(S0, K, T, r, sigma, N, M)
  dt = T / N
  paths = Matrix.build(N + 1, M) { |i, j| i == 0 ? S0 : nil }
  paths[0, true] = S0
  for i in 1..N
    Z = Array.new(M) { randn }
    paths[i, true] = paths[i - 1, true].map.with_index { |s, j| s * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Z[j]) }
  end
  paths
end

def calculate_payoffs(paths, K, T, r, M)
  S_T = paths.row(paths.row_count - 1)
  payoff = S_T.map { |s| [s - K, 0].max }
  option_value = Math.exp(-r * T) * payoff.sum / M.to_f
  option_value
end

def main
  S0 = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  N = 252
  M = 100000
  while true
    paths = simulate_paths(S0, K, T, r, sigma, N, M)
    option_value = calculate_payoffs(paths, K, T, r, M)
    puts option_value
  end
end

main