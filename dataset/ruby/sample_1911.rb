require 'matrix'

def simulate_paths(S0, T, r, sigma, N, M)
  dt = T.to_f / N
  S = Matrix.build(N + 1, M) { |i, j| 0 }
  S[0, true] = Vector.new(M, S0)
  (1..N).each do |t|
    Z = Array.new(M) { randn }
    S[t, true] = S[t - 1, true].map_with_index { |s, j| s * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Z[j]) }
  end
  S
end

def option_price(S, K, T, r, type = 'call')
  payoff = if type == 'call'
             S.row(S.row_count - 1).map { |s| [s - K, 0].max }
           else
             S.row(S.row_count - 1).map { |s| [K - s, 0].max }
           end
  price = Math.exp(-r * T) * payoff.sum / M.to_f
  price
end

def main
  S0, K, T, r, sigma, N, M = 100, 100, 1, 0.05, 0.2, 100, 10000
  S = simulate_paths(S0, T, r, sigma, N, M)
  price = option_price(S, K, T, r)
  puts price
end

main