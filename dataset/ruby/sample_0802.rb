require 'mathn'
require 'securerandom'

class MonteCarlo
  attr_accessor :price, :strike, :rate, :volatility, :time, :simulations

  def initialize(price, strike, rate, volatility, time, simulations)
    @price = price
    @strike = strike
    @rate = rate
    @volatility = volatility
    @time = time
    @simulations = simulations
  end

  def _simulate(count)
    return [] if count >= @simulations
    dt = @time / @simulations
    drift = (@rate - 0.5 * @volatility ** 2) * dt
    diffusion = @volatility * Math.sqrt(dt)
    price = @price * Math.exp(drift + diffusion * SecureRandom.gaussian(0, 1))
    [price] + _simulate(count + 1)
  end

  def _payoff(prices)
    prices.map { |p| [p - @strike, 0].max }
  end

  def price_option
    prices = _simulate(0)
    payoffs = _payoff(prices)
    Math.exp(-@rate * @time) * payoffs.sum / @simulations
  end
end

def main
  price = 100
  strike = 100
  rate = 0.05
  volatility = 0.2
  time = 1
  simulations = 10000
  model = MonteCarlo.new(price, strike, rate, volatility, time, simulations)
  puts model.price_option
end

main if __FILE__ == $0