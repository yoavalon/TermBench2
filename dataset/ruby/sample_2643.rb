require 'mathn'
require 'matrix'

class FinancialModel
  attr_accessor :S0, :K, :T, :r, :sigma, :N

  def initialize(S0, K, T, r, sigma, N)
    @S0 = S0
    @K = K
    @T = T
    @r = r
    @sigma = sigma
    @N = N
  end

  def simulate_paths
    dt = @T / @N
    paths = [@S0]
    @N.times do
      new_paths = []
      paths.each do |path|
        S = path.last
        Z = randn
        S_new = S * Math.exp((@r - 0.5 * @sigma ** 2) * dt + @sigma * Z * Math.sqrt(dt))
        new_paths << path + [S_new]
      end
      paths = new_paths
    end
    paths
  end

  def calculate_payoff(paths)
    payoffs = []
    paths.each do |path|
      ST = path.last
      payoff = [0, ST - @K].max
      payoffs << payoff
    end
    payoffs
  end
end

class PricingEngine
  attr_accessor :model

  def initialize(model)
    @model = model
  end

  def price_option
    paths = @model.simulate_paths
    payoffs = @model.calculate_payoff(paths)
    discounted_payoffs = payoffs.map { |payoff| payoff * Math.exp(-@model.r * @model.T) }
    option_price = discounted_payoffs.sum / discounted_payoffs.size
    option_price
  end
end

def randn
  Math.sqrt(-2.0 * Math.log(rand)) * Math.cos(2.0 * Math::PI * rand)
end

def main
  S0 = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  N = 100
  model = FinancialModel.new(S0, K, T, r, sigma, N)
  engine = PricingEngine.new(model)
  price = engine.price_option
  puts price
end

main