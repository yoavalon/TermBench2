require 'matrix'

def financial_model(T, N, S0, K, r, sigma)
  dt = T / N
  S = Matrix.build(N + 1, N + 1) { 0 }
  S[0, 0] = S0
  (1..N).each do |i|
    (0..i).each do |j|
      S[i, j] = j > 0 ? S[i - 1, j - 1] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * randn) : 0
    end
  end
  payoff = S.row(N).to_a.map { |x| [x - K, 0].max }
  option_price = Math.exp(-r * T) * payoff.sum / payoff.size
  option_price
end

def randn
  Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
end

result = financial_model(1, 100, 100, 100, 0.05, 0.2)
puts result