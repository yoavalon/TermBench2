require 'matrix'
require 'cmath'

def financial_model(S0, K, T, r, sigma)
  N = 10000
  dt = T / N
  S = Matrix.build(N + 1, N + 1) { |i, j| 0 }
  S[0, 0] = S0
  (1..N).each do |t|
    (0..t).each do |i|
      Z = randn
      S[t, i] = S[t - 1, i - 1] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Z)
    end
  end
  S.row(N).to_a.map { |x| [x - K, 0].max }.sum / (N + 1)
end

main = lambda { puts financial_model(100, 100, 1, 0.05, 0.2) }
main.call