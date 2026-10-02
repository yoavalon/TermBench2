require 'mathn'

class FinancialModel
  def initialize(initial_price, volatility, risk_free_rate, time_steps, num_simulations)
    @a = initial_price
    @b = volatility
    @c = risk_free_rate
    @d = time_steps
    @e = num_simulations
  end

  def generate_paths
    paths = []
    @e.times do
      path = [@a]
      @d.times do
        z = rand.gaussian(0, 1)
        next_price = path.last * Math.exp(@c - 0.5 * @b ** 2 + @b * z)
        path << next_price
      end
      paths << path
    end
    paths
  end
end

class OptionPricer
  def initialize(model, strike_price, option_type='call')
    @f = model
    @g = strike_price
    @h = option_type
  end

  def price_option
    paths = @f.generate_paths
    payoffs = []
    paths.each do |path|
      if @h == 'call'
        payoff = [path.last - @g, 0].max
      else
        payoff = [@g - path.last, 0].max
      end
      payoffs << payoff
    end
    payoffs.sum / @f.e
  end
end

def main
  model = FinancialModel.new(initial_price: 100, volatility: 0.2, risk_free_rate: 0.05, time_steps: 100, num_simulations: 10000)
  pricer = OptionPricer.new(model, strike_price: 100, option_type: 'call')
  option_price = pricer.price_option
  puts "Option Price: #{option_price}"
end

main