require 'matrix'
require 'random'

class FinancialModel
  def initialize(S0, K, T, r, sigma, N)
    @S0 = S0
    @K = K
    @T = T
    @r = r
    @sigma = sigma
    @N = N
    @dt = T / N
  end

  def simulate_paths
    paths = Array.new(@N + 1) { Array.new(@S0.size) }
    paths[0] = @S0
    (1..@N).each do |t|
      z = Array.new(@S0.size) { Random.normal }
      paths[t] = paths[t - 1].map.with_index do |s, i|
        s * Math.exp((@r - 0.5 * @sigma ** 2) * @dt + @sigma * Math.sqrt(@dt) * z[i])
      end
    end
    paths
  end

  def payoff(paths)
    payoff = paths.last.map { |s| [s - @K, 0].max }
    payoff
  end
end

class OptionPricer
  def initialize(financial_model, M)
    @financial_model = financial_model
    @M = M
  end

  def price_option
    payoffs = Array.new(@M)
    (0...@M).each do |i|
      paths = @financial_model.simulate_paths
      payoffs[i] = @financial_model.payoff(paths)
    end
    option_price = Math.exp(-@financial_model.r * @financial_model.T) * payoffs.flatten.sum / @M
    option_price
  end
end

def main
  S0 = [100, 100, 100]
  K = 100
  T = 1.0
  r = 0.05
  sigma = 0.2
  N = 100
  M = 10000
  financial_model = FinancialModel.new(S0, K, T, r, sigma, N)
  option_pricer = OptionPricer.new(financial_model, M)
  puts option_pricer.price_option
end

main if __FILE__ == $0