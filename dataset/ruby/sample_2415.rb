require 'matrix'
require 'statistics'

def simulate_option_price(S0, K, T, r, sigma, steps, trials)
  dt = T / steps
  dW = Matrix.build(steps, trials) { randn * Math.sqrt(dt) }
  S = Matrix.build(steps, trials) do |i, j|
    if i == 0
      S0
    else
      S[i-1, j] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * dW[0..i-1, j].sum)
    end
  end
  payoff = S.row(steps - 1).map { |s| [s - K, 0].max }
  Math.exp(-r * T) * Statistics.mean(payoff)
end

simulate_option_price(100, 100, 1, 0.05, 0.2, 100, 1000)