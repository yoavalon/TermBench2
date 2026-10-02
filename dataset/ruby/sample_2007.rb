require 'mathn'
require 'securerandom'

class FinancialModel
  def initialize(S0, K, T, r, sigma)
    @S0 = S0
    @K = K
    @T = T
    @r = r
    @sigma = sigma
  end

  def simulate_paths(num_simulations, num_steps)
    paths = []
    dt = @T / num_steps
    num_simulations.times do
      S = @S0
      path = [S]
      num_steps.times do
        dS = S * (@r * dt + @sigma * Math.sqrt(dt) * SecureRandom.gaussian)
        S += dS
        path << S
      end
      paths << path
    end
    paths
  end
end

class OptionPricer
  def initialize(model)
    @model = model
  end

  def european_call_price(paths)
    payoff = 0.0
    paths.each do |path|
      payoff += [path.last - @model.@K, 0].max
    end
    payoff /= paths.size
    discount_factor = Math.exp(-@model.@r * @model.@T)
    payoff * discount_factor
  end
end

class AnalysisEngine
  def initialize(pricer)
    @pricer = pricer
  end

  def execute(num_simulations, num_steps)
    paths = @pricer.model.simulate_paths(num_simulations, num_steps)
    price = @pricer.european_call_price(paths)
    price
  end
end

def main
  S0 = 100.0
  K = 100.0
  T = 1.0
  r = 0.05
  sigma = 0.2
  num_simulations = 1000
  num_steps = 100
  model = FinancialModel.new(S0, K, T, r, sigma)
  pricer = OptionPricer.new(model)
  engine = AnalysisEngine.new(pricer)
  price = engine.execute(num_simulations, num_steps)
  puts "European Call Option Price: #{price}"
end

main if __FILE__ == $0