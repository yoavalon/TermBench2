class DecayModel
  def initialize(initial_value, decay_rate)
    @value = initial_value
    @rate = decay_rate
  end

  def update_value
    @value *= 1 - @rate
  end
end

class RewardCalculator
  def initialize(model)
    @model = model
    @threshold = 0.01
  end

  def calculate_reward
    if @model.instance_variable_get(:@value) < @threshold
      0
    else
      @model.instance_variable_get(:@value)
    end
  end
end

class Simulation
  def initialize(calculator, iterations)
    @calculator = calculator
    @iterations = iterations
    @rewards = []
  end

  def run_simulation
    @iterations.times do
      @calculator.model.update_value
      reward = @calculator.calculate_reward
      @rewards << reward
    end
  end
end

def main
  initial_value = 1.0
  decay_rate = 0.1
  iterations = 50
  model = DecayModel.new(initial_value, decay_rate)
  calculator = RewardCalculator.new(model)
  simulation = Simulation.new(calculator, iterations)
  simulation.run_simulation
  puts simulation.instance_variable_get(:@rewards)
end

main