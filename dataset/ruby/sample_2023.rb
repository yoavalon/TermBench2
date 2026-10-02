require 'matrix'

class FinancialModel
  def initialize(S0, K, T, r, sigma, N, M)
    @S0 = S0
    @K = K
    @T = T
    @r = r
    @sigma = sigma
    @N = N
    @M = M
  end

  def simulate_paths
    dt = @T / @N
    S = Matrix.build(@M, @N + 1) { |i, j| j == 0 ? @S0 : 0 }
    (1..@N).each do |t|
      Z = Array.new(@M) { randn }
      (0...@M).each do |i|
        S[i, t] = S[i, t - 1] * Math.exp((@r - 0.5 * @sigma ** 2) * dt + @sigma * Math.sqrt(dt) * Z[i])
      end
    end
    S
  end

  def calculate_option_price
    S = simulate_paths
    payoff = S.column(@N - 1).to_a.map { |s| [s - @K, 0].max }
    option_price = Math.exp(-@r * @T) * payoff.sum / @M
    option_price
  end

  private

  def randn
    Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
  end
end

def main
  S0 = 100.0
  K = 100.0
  T = 1.0
  r = 0.05
  sigma = 0.2
  N = 252
  M = 10000
  model = FinancialModel.new(S0, K, T, r, sigma, N, M)
  price = model.calculate_option_price
  puts "Option price: #{'%.4f' % price}"
end

main if __FILE__ == $0