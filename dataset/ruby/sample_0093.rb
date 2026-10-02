require 'matrix'
require 'mathn'

def monte_carlo_pricing(S0, K, T, r, sigma, N, M)
  dt = T.to_f / M
  S = Matrix.build(M + 1, N) { 0 }
  S[0, true] = Vector.build(N) { S0 }
  for t in 1..M
    Z = Vector.build(N) { randn }
    S[t, true] = S[t - 1, true].map.with_index { |s, i| s * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Z[i]) }
  end
  payoff = S[M, true].map { |s| [s - K, 0].max }
  Math.exp(-r * T) * payoff.sum.to_f / N
end

def randn
  Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
end

monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000, 100)