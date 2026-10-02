require 'random'
require 'mathn'

class FinancialModel
  def initialize(initial_price, volatility, risk_free_rate, strike_price, maturity)
    @S0 = initial_price
    @sigma = volatility
    @r = risk_free_rate
    @K = strike_price
    @T = maturity
  end

  def simulate_paths(num_paths, num_steps)
    dt = @T / num_steps
    paths = Array.new(num_paths) { [@S0] }
    num_steps.times do
      num_paths.times do |i|
        Z = rand.gaussian(0, 1)
        S_next = paths[i].last * Math.exp((@r - 0.5 * @sigma ** 2) * dt + @sigma * Math.sqrt(dt) * Z)
        paths[i] << S_next
      end
    end
    paths
  end
end

class OptionPricing
  def initialize(model, num_paths, num_steps)
    @model = model
    @num_paths = num_paths
    @num_steps = num_steps
  end

  def calculate_option_value
    paths = @model.simulate_paths(@num_paths, @num_steps)
    option_values = paths.map do |path|
      payoff = [path.last - @model.@K, 0].max
      payoff
    end
    option_values.sum / @num_paths * Math.exp(-@model.@r * @model.@T)
  end
end

def main
  initial_price = 100
  volatility = 0.2
  risk_free_rate = 0.05
  strike_price = 100
  maturity = 1
  num_paths = 1000
  num_steps = 100
  model = FinancialModel.new(initial_price, volatility, risk_free_rate, strike_price, maturity)
  option_pricing = OptionPricing.new(model, num_paths, num_steps)
  value = option_pricing.calculate_option_value
  puts "Option Value: #{value}"
end

main