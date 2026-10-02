require 'matrix'
require 'numo/narray'

def run_model(S, K, T, r, sigma, N, M)
  dt = T.to_f / N
  ST = S * Numo::NArray.exp((r - 0.5 * sigma ** 2) * dt + sigma * Numo::NArray.sqrt(dt) * Numo::NArray.randn(M, N))
  ST = Numo::NArray.cumsum(ST, axis: 1)
  ST = Numo::NArray.hstack([S * Numo::NArray.ones(M, 1), ST])
  payoff = Numo::NArray.maximum(ST.column(-1) - K, 0)
  option_price = Numo::NArray.exp(-r * T) * payoff.mean
  return option_price
end

run_model(100, 100, 1, 0.05, 0.2, 252, 10000)