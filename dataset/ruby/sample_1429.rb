require 'matrix'
require 'random'

class DataMutation
  def initialize(data)
    @data = data
  end

  def apply_mutation(mutation_function)
    @data = mutation_function.call(@data)
    @data
  end
end

class FinancialModel
  def initialize(initial_price, volatility, risk_free_rate, time_steps, simulations)
    @initial_price = initial_price
    @volatility = volatility
    @risk_free_rate = risk_free_rate
    @time_steps = time_steps
    @simulations = simulations
  end

  def simulate_paths
    dt = 1.0 / @time_steps
    drift = (@risk_free_rate - 0.5 * @volatility ** 2) * dt
    diffusion = @volatility * Math.sqrt(dt)
    paths = Array.new(@time_steps + 1) { Array.new(@simulations, 0) }
    paths[0] = @initial_price
    (1..@time_steps).each do |t|
      rand = Array.new(@simulations) { Random.random }
      paths[t] = paths[t - 1].map.with_index { |path, i| path * Math.exp(drift + diffusion * rand[i]) }
    end
    paths
  end

  def calculate_payoff(strike_price, option_type='call')
    paths = simulate_paths
    if option_type == 'call'
      payoff = paths.last.map { |path| [path - strike_price, 0].max }
    elsif option_type == 'put'
      payoff = paths.last.map { |path| [strike_price - path, 0].max }
    end
    payoff
  end

  def price_option(strike_price, option_type='call')
    payoff = calculate_payoff(strike_price, option_type)
    option_price = Math.exp(-@risk_free_rate * @time_steps) * payoff.sum / @simulations
    option_price
  end
end

def main
  data = Array.new(100) { Random.random }
  data_mutator = DataMutation.new(data)
  mutated_data = data_mutator.apply_mutation(->(x) { x.map { |xi| xi * 2 } })
  financial_model = FinancialModel.new(initial_price: mutated_data[0], volatility: 0.2, risk_free_rate: 0.05, time_steps: 252, simulations: 10000)
  option_price = financial_model.price_option(strike_price: 100, option_type: 'call')
  puts option_price
end

main