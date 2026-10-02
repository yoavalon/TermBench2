require 'matrix'
require 'nmatrix'

def monte_carlo_pricing(S, K, T, r, sigma, N, M)
  dt = T / M
  S_t = NMatrix.new([N, M + 1], S)
  (1..M).each do |t|
    z = NMatrix.random([N, 1], :type => :float64, :distribution => :normal)
    S_t.column(t) = S_t.column(t - 1) * (Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z))
  end
  payoff = S_t.column(M).max(0) - K
  option_price = Math.exp(-r * T) * payoff.mean
  option_price
end

monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000, 100)