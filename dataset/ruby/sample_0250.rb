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
    paths = Matrix.build(@N + 1, @M) { |i, j| 0 }
    paths.row(0).each_with_index { |_, j| paths[0, j] = @S0 }
    (1..@N).each do |i|
      z = Array.new(@M) { randn }
      paths.row(i).each_with_index do |_, j|
        paths[i, j] = paths[i - 1, j] * Math.exp((@r - 0.5 * @sigma ** 2) * dt + @sigma * Math.sqrt(dt) * z[j])
      end
    end
    paths
  end

  def option_price
    paths = simulate_paths
    payoff = paths.row(@N).to_a.map { |x| [x - @K, 0].max }
    price = Math.exp(-@r * @T) * payoff.sum / @M
    price
  end

  def randn
    Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
  end
end

def main
  S0 = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  N = 100
  M = 10000
  model = FinancialModel.new(S0, K, T, r, sigma, N, M)
  price = model.option_price
  puts price
end

main