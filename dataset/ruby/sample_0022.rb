require 'matrix'

def financial_model(S, K, T, r, sigma, N, M)
  dt = T.to_f / N
  S_t = S.to_f
  N.times do
    z = Array.new(M) { randn }
    S_t *= Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z)
  end
  payoff = S_t.map { |s| [s - K, 0].max }
  option_price = Math.exp(-r * T) * payoff.sum / M.to_f
  option_price
end

result = financial_model(100, 100, 1, 0.05, 0.2, 100, 10000)
puts result

def randn
  Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
end