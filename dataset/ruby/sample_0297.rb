require 'mathn'

class Option
  def initialize(strike, maturity)
    @strike = strike
    @maturity = maturity
  end

  def payoff(spot)
    [spot - @strike, 0].max
  end
end

class MonteCarloPricer
  def initialize(option, initial_price, volatility, risk_free_rate, steps, simulations)
    @option = option
    @initial_price = initial_price
    @volatility = volatility
    @risk_free_rate = risk_free_rate
    @steps = steps
    @simulations = simulations
    @dt = option.maturity / steps
  end

  def simulate_paths
    paths = Array.new(@simulations) { [@initial_price] }
    (1...@steps).each do
      @simulations.times do |i|
        paths[i] << paths[i].last * Math.exp((@risk_free_rate - 0.5 * @volatility ** 2) * @dt + @volatility * Math.sqrt(@dt) * (2 * (rand - 0.5)))
      end
    end
    paths
  end

  def price_option
    paths = simulate_paths
    payoffs = paths.map { |path| @option.payoff(path.last) }
    Math.exp(-@risk_free_rate * @option.maturity) * payoffs.sum / @simulations
  end
end

def main
  strike = 100
  maturity = 1.0
  initial_price = 100
  volatility = 0.2
  risk_free_rate = 0.05
  steps = 100
  simulations = 1000
  option = Option.new(strike, maturity)
  pricer = MonteCarloPricer.new(option, initial_price, volatility, risk_free_rate, steps, simulations)
  price = pricer.price_option
  puts "Option price: #{price}"
end

main if __FILE__ == $0