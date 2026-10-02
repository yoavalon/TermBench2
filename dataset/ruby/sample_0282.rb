require 'matrix'
require 'random'

class FinancialModel
  def initialize(s0, k, t, r, sigma, n_simulations)
    @s0 = s0
    @k = k
    @t = t
    @r = r
    @sigma = sigma
    @n_simulations = n_simulations
  end

  def simulate_paths
    dt = @t / 365.0
    paths = Matrix.build(@n_simulations, 365) { |row, col| 0.0 }
    (0...@n_simulations).each { |i| paths[i, 0] = @s0 }
    (1...365).each do |i|
      z = Array.new(@n_simulations) { Random.randn }
      (0...@n_simulations).each { |j| paths[j, i] = paths[j, i - 1] * Math.exp((@r - 0.5 * @sigma**2) * dt + @sigma * Math.sqrt(dt) * z[j]) }
    end
    paths
  end

  def calculate_payoff(paths)
    payoff = paths.column(paths.column_count - 1).to_a.map { |s| [s - @k, 0].max }
    payoff
  end
end

class OptionPricer
  def initialize(model)
    @model = model
  end

  def price_option
    paths = @model.simulate_paths
    payoff = @model.calculate_payoff(paths)
    option_price = Math.exp(-@model.r * @model.t) * payoff.sum / @model.n_simulations
    option_price
  end
end

def main
  s0 = 100
  k = 100
  t = 1
  r = 0.05
  sigma = 0.2
  n_simulations = 10000
  model = FinancialModel.new(s0, k, t, r, sigma, n_simulations)
  pricer = OptionPricer.new(model)
  price = pricer.price_option
  puts price
end

main if __FILE__ == $0