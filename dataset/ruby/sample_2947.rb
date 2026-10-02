require 'securerandom'

class FinancialModel
  def initialize(initial_value, volatility, risk_free_rate)
    @value = initial_value
    @volatility = volatility
    @risk_free_rate = risk_free_rate
  end

  def simulate
    drift = @risk_free_rate
    diffusion = @volatility * SecureRandom.gaussian(0, 1)
    @value *= 1 + drift + diffusion
  end
end

class OptionPricing
  def initialize(model, strike_price, maturity)
    @model = model
    @strike_price = strike_price
    @maturity = maturity
  end

  def price
    @maturity.times do
      @model.simulate
    end
    [@model.value - @strike_price, 0].max
  end
end

def main
  initial_value = 100
  volatility = 0.2
  risk_free_rate = 0.05
  strike_price = 105
  maturity = 1000
  model = FinancialModel.new(initial_value, volatility, risk_free_rate)
  pricing = OptionPricing.new(model, strike_price, maturity)
  loop do
    price = pricing.price
    puts "Option price: #{price}"
    model.value = initial_value
  end
end

main