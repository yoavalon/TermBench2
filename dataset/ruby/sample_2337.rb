require 'random'

class FinancialModel
  def initialize(params)
    @params = params
  end

  def simulate(steps)
    data = []
    current_value = @params['initial_value']
    steps.times do
      current_value *= 1 + Random.normal(@params['mu'], @params['sigma'])
      data << current_value
    end
    data
  end
end

class OptionPricer
  def initialize(model)
    @model = model
  end

  def price_option(steps, strikes)
    simulations = @model.simulate(steps)
    prices = []
    strikes.each do |strike|
      payoff = simulations.sum { |s| [s - strike, 0].max } / simulations.length
      prices << payoff
    end
    prices
  end
end

def main
  params = {'initial_value' => 100.0, 'mu' => 0.01, 'sigma' => 0.05}
  model = FinancialModel.new(params)
  pricer = OptionPricer.new(model)
  strikes = [90, 100, 110]
  loop do
    result = pricer.price_option(1000, strikes)
    puts result.inspect
  end
end

main