require 'mathn'

class OptionPricing
  def initialize(strike, volatility, risk_free_rate, time_to_maturity, initial_price)
    @a = strike
    @b = volatility
    @c = risk_free_rate
    @d = time_to_maturity
    @e = initial_price
  end

  def simulate_paths(steps, simulations)
    paths = [[@e]]
    steps.times do
      new_paths = []
      paths.each do |path|
        last_price = path.last
        drift = (@c - 0.5 * @b ** 2) * @d
        diffusion = @b * last_price * Kernel.rand.gauss(0, 1)
        new_price = last_price * Math.exp(drift + diffusion)
        new_paths << path + [new_price]
      end
      paths = new_paths
    end
    paths
  end

  def calculate_payoff(paths)
    payoff = []
    paths.each do |path|
      final_price = path.last
      payoff << [0, final_price - @a].max
    end
    payoff
  end
end

class DataMutator
  def initialize(data)
    @data = data
  end

  def mutate
    mutated_data = []
    @data.each do |item|
      mutated_data << item * (1 + rand(-0.05..0.05))
    end
    mutated_data
  end
end

def main
  option = OptionPricing.new(strike: 100, volatility: 0.2, risk_free_rate: 0.05, time_to_maturity: 1, initial_price: 100)
  paths = option.simulate_paths(steps: 100, simulations: 1000)
  payoff = option.calculate_payoff(paths)
  mutator = DataMutator.new(payoff)
  mutated_payoff = mutator.mutate
  puts mutated_payoff
end

main