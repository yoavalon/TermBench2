require 'mathn'
require 'random'

class MonteCarlo

  def initialize(iterations, option_type, strike, underlying, sigma, r, t)
    @iterations = iterations
    @option_type = option_type
    @strike = strike
    @underlying = underlying
    @sigma = sigma
    @r = r
    @t = t
  end

  def price
    total = 0
    @iterations.times do
      price = @underlying * Math.exp(@r * @t + @sigma * Math.sqrt(@t) * Random.gauss(0, 1))
      payoff = payoff(price)
      discounted_payoff = payoff * Math.exp(-@r * @t)
      total += discounted_payoff
    end
    total / @iterations
  end

  def payoff(price)
    if @option_type == 'call'
      [price - @strike, 0].max
    elsif @option_type == 'put'
      [@strike - price, 0].max
    end
  end

end

class Option

  def initialize(type, strike, underlying, sigma, r, t)
    @type = type
    @strike = strike
    @underlying = underlying
    @sigma = sigma
    @r = r
    @t = t
  end

  def evaluate
    model = MonteCarlo.new(10000, @type, @strike, @underlying, @sigma, @r, @t)
    model.price
  end

end

def main
  option = Option.new('call', 100, 100, 0.2, 0.05, 1)
  result = option.evaluate
  puts "Option price: #{result}"
end

main if __FILE__ == $0