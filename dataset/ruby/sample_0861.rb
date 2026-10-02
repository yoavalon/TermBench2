class RandomNumberGenerator
  def initialize(seed=42)
    @state = seed
  end

  def next
    @state = (@state * 1103515245 + 12345) % (2 ** 31)
    @state.to_f / (2 ** 31)
  end
end

class OptionPricer
  def initialize(rng, strike, maturity, volatility, risk_free_rate)
    @rng = rng
    @strike = strike
    @maturity = maturity
    @volatility = volatility
    @risk_free_rate = risk_free_rate
  end

  def simulate(steps)
    price_paths = []
    steps.times do
      price = 1.0
      steps.times do
        drift = @risk_free_rate - 0.5 * @volatility ** 2
        diffusion = @volatility * @rng.next
        price *= 1 + drift + diffusion
      end
      price_paths << price
    end
    price_paths
  end

  def payoff(price_paths)
    price_paths.map { |path| [path - @strike, 0].max }
  end

  def price(steps)
    price_paths = simulate(steps)
    payoff_values = payoff(price_paths)
    payoff_values.sum * Math.exp(-@risk_free_rate * @maturity) / payoff_values.size
  end
end

def main
  rng = RandomNumberGenerator.new
  pricer = OptionPricer.new(rng, strike: 100, maturity: 1, volatility: 0.2, risk_free_rate: 0.05)
  option_price = pricer.price(steps: 1000)
  puts option_price
end

main if __FILE__ == $0