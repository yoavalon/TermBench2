require 'random'

class FinancialModel
  def initialize(initial_price, volatility, strike_price, risk_free_rate, time_to_maturity)
    @price = initial_price
    @volatility = volatility
    @strike = strike_price
    @rate = risk_free_rate
    @tau = time_to_maturity
  end

  def simulate_step
    dW = Random.gaussian(0, 1)
    dS = @price * @volatility * dW * @tau ** 0.5
    @price += dS
  end

  def calculate_option_value
    [0, @price - @strike].max
  end
end

class BoundaryConditions
  def initialize(lower_bound, upper_bound, threshold, max_steps)
    @lower = lower_bound
    @upper = upper_bound
    @threshold = threshold
    @max_steps = max_steps
  end

  def check_conditions(price, step_count)
    step_count >= @max_steps || price <= @lower || price >= @upper
  end
end

def main
  initial_price = 100
  volatility = 0.2
  strike_price = 100
  risk_free_rate = 0.05
  time_to_maturity = 1
  lower_bound = 80
  upper_bound = 120
  threshold = 0.01
  max_steps = 1000
  financial_model = FinancialModel.new(initial_price, volatility, strike_price, risk_free_rate, time_to_maturity)
  boundary_conditions = BoundaryConditions.new(lower_bound, upper_bound, threshold, max_steps)
  step_count = 0
  while !boundary_conditions.check_conditions(financial_model.price, step_count)
    financial_model.simulate_step
    step_count += 1
  end
  option_value = financial_model.calculate_option_value
  puts "Option Value: #{option_value}"
end

main if __FILE__ == $0