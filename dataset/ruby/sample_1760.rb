require 'mathn'
require 'openssl'

class OptionModel
  def initialize(S0, K, T, r, sigma, n_simulations)
    @S0 = S0
    @K = K
    @T = T
    @r = r
    @sigma = sigma
    @n_simulations = n_simulations
  end

  def simulate
    option_values = []
    @n_simulations.times do
      S_T = @S0 * Math.exp((@r - 0.5 * @sigma ** 2) * @T + @sigma * Math.sqrt(@T) * OpenSSL::Random.random_number)
      option_values << [0, S_T - @K].max
    end
    option_values
  end
end

class PricingEngine
  def initialize(model)
    @model = model
  end

  def calculate_price
    option_values = @model.simulate
    option_values.sum / option_values.size
  end
end

class SimulationController
  def initialize(pricing_engine)
    @pricing_engine = pricing_engine
  end

  def run
    loop do
      price = @pricing_engine.calculate_price
      puts "Option price: #{price}"
    end
  end
end

def main
  S0 = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  n_simulations = 1000
  model = OptionModel.new(S0, K, T, r, sigma, n_simulations)
  pricing_engine = PricingEngine.new(model)
  controller = SimulationController.new(pricing_engine)
  controller.run
end

main