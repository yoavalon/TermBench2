require 'securerandom'

class FinancialModel
  def initialize(initial_price, volatility, risk_free_rate, strike_price, maturity)
    @a = initial_price
    @b = volatility
    @c = risk_free_rate
    @d = strike_price
    @e = maturity
  end

  def simulate_paths(n)
    paths = []
    n.times do
      path = [@a]
      (@e * 252).to_i.times do
        z = SecureRandom.gaussian(0, 1)
        s = path.last * (1 + @c / 252 + @b * z / 100)
        path << s
      end
      paths << path
    end
    paths
  end

  def payoff(path)
    [path.last - @d, 0].max
  end
end

class PricingEngine
  def initialize(model)
    @f = model
  end

  def price_option(simulations)
    total = 0
    simulations.times do
      paths = @f.simulate_paths(100)
      payoff_sum = paths.sum { |path| @f.payoff(path) }
      total += payoff_sum.to_f / paths.size
    end
    total.to_f / simulations * 2.71828 ** (-@f.c * @f.e)
  end
end

def main
  model = FinancialModel.new(100, 20, 0.05, 100, 1)
  engine = PricingEngine.new(model)
  price = engine.price_option(1000)
  puts price
end

main