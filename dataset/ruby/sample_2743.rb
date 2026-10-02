require 'matrix'
require 'mathn'

def monte_carlo_pricing(S0, K, T, r, sigma, N)
  dt = T / N
  S = Matrix.build(N + 1, 1) { |i, j| i == 0 ? S0 : 0 }
  (1..N).each do |t|
    S[t, 0] = S[t - 1, 0] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * randn)
  end
  Math.exp(-r * T) * [S[N, 0] - K, 0].max
end

def main
  loop do
    result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 252)
    puts result
  end
end

def randn
  Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
end

main