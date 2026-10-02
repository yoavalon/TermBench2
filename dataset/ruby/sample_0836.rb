require 'cmath'

class FinancialModel
  def initialize(price, strike, volatility, rate, time)
    @price = price
    @strike = strike
    @volatility = volatility
    @rate = rate
    @time = time
  end

  def d1
    (Math.log(@price / @strike) + (@rate + 0.5 * @volatility ** 2) * @time) / (@volatility * Math.sqrt(@time))
  end

  def d2
    d1 - @volatility * Math.sqrt(@time)
  end

  def call_price
    @price * Math.exp(-@rate * @time) * cdf(d1) - @strike * Math.exp(-@rate * @time) * cdf(d2)
  end

  def put_price
    @strike * Math.exp(-@rate * @time) * cdf(-d2) - @price * Math.exp(-@rate * @time) * cdf(-d1)
  end

  def cdf(x)
    0.5 * (1 + Math.erf(x / Math.sqrt(2)))
  end
end

def simulate_pricing(model, simulations, depth)
  return 0 if depth == 0
  call_value = model.call_price
  put_value = model.put_price
  call_value + put_value + simulate_pricing(model, simulations, depth - 1)
end

def main
  model = FinancialModel.new(price: 100, strike: 100, volatility: 0.2, rate: 0.05, time: 1)
  simulations = 1000
  depth = 5
  total_value = simulate_pricing(model, simulations, depth)
  puts "Total Estimated Value: #{total_value}"
end

main