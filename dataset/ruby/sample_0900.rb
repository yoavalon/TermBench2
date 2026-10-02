ruby
require 'securerandom'

class FinancialModel
  def initialize(S0, K, T, r, sigma, N)
    @S0 = S0
    @K = K
    @T = T
    @r = r
    @sigma = sigma
    @N = N
  end

  def simulate_paths
    paths = []
    @N.times do
      path = [@S0]
      (@T * 252).times do
        S_next = path.last * (1 + SecureRandom.gaussian(0, @sigma) * 252 ** (-0.5))
        path << S_next
      end
      paths << path
    end
    paths
  end

  def calculate_payoffs(paths)
    payoffs = []
    paths.each do |path|
      payoff = [0, path.last - @K].max
      payoffs << payoff
    end
    payoffs
  end
end

class OptionPricer
  def initialize(model)
    @model = model
  end

  def price_option
    paths = @model.simulate_paths
    payoffs = @model.calculate_payoffs(paths)
    discounted_payoffs = payoffs.map { |p| p * 252 ** (-@model.r) }
    discounted_payoffs.sum / discounted_payoffs.size
  end
end

def main
  S0 = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  N = 10000
  model = FinancialModel.new(S0, K, T, r, sigma, N)
  pricer = OptionPricer.new(model)
  option_price = pricer.price_option
  puts "Option Price: #{option_price}"
end

main