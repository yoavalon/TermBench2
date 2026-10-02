require 'matrix'

def generate_paths(S0, mu, sigma, T, N, M)
  dt = T / N
  S = Matrix.build(N + 1, M) { 0 }
  S[0, 0...M] = S0
  (1..N).each do |t|
    S[t, 0...M] = S[t - 1, 0...M] * Math.exp((mu - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Array.new(M) { randn })
  end
  S
end

def option_price(paths, K, r, T, payoff)
  discounted_payoffs = Array.new(paths.column_size) { |i| Math.exp(-r * T) * payoff(paths.row(paths.row_size - 1).to_a[i], K) }
  discounted_payoffs.sum / discounted_payoffs.size.to_f
end

def main
  S0 = 100
  K = 100
  r = 0.05
  T = 1
  N = 252
  M = 10000
  sigma = 0.2
  mu = 0.1

  def european_call(S, K)
    [S - K, 0].max
  end

  paths = generate_paths(S0, mu, sigma, T, N, M)
  call_price = option_price(paths, K, r, T, method(:european_call))
  puts call_price
end

main