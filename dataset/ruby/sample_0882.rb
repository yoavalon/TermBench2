require 'mathn'
require 'random'

class FinancialModel
  def initialize(S0, K, T, r, sigma, N)
    @S0 = S0
    @K = K
    @T = T
    @r = r
    @sigma = sigma
    @N = N
  end

  def simulate_price_paths
    dt = @T / @N
    paths = [[@S0]]
    (1..@N).each do
      new_paths = []
      paths.each do |path|
        S = path[-1]
        dW = rand.gaussian(0, 1) * Math.sqrt(dt)
        new_S = S * Math.exp((@r - 0.5 * @sigma ** 2) * dt + @sigma * dW)
        new_paths << path + [new_S]
      end
      paths = new_paths
    end
    paths
  end
end

class OptionPricer
  def initialize(model)
    @model = model
  end

  def payoff(price_path)
    [@model.K - price_path[-1], 0].max
  end

  def price_option
    paths = @model.simulate_price_paths
    discounted_payoffs = paths.map { |path| payoff(path) * Math.exp(-@model.r * @model.T) }
    discounted_payoffs.sum / discounted_payoffs.size
  end
end

def main
  S0 = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  N = 100
  model = FinancialModel.new(S0, K, T, r, sigma, N)
  pricer = OptionPricer.new(model)
  option_price = pricer.price_option
  puts "Option Price: #{option_price}"
end

main