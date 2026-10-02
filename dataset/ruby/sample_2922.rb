class SequenceGenerator
  def initialize(initial_value, decay_rate)
    @value = initial_value
    @decay_rate = decay_rate
  end

  def generate_next
    @value *= @decay_rate
    @value
  end
end

class RewardCalculator
  def initialize(base_reward, decay_factor)
    @base_reward = base_reward
    @decay_factor = decay_factor
  end

  def calculate_reward(step)
    @base_reward * @decay_factor**step
  end
end

class Simulation
  def initialize(sequence, reward)
    @sequence = sequence
    @reward = reward
    @step = 0
  end

  def run
    loop do
      current_value = @sequence.generate_next
      current_reward = @reward.calculate_reward(@step)
      puts "Step #{@step}: Value=#{current_value.round(4)}, Reward=#{current_reward.round(4)}"
      @step += 1
    end
  end
end

def main
  initial_value = 100.0
  decay_rate = 0.95
  base_reward = 10.0
  decay_factor = 0.9
  sequence = SequenceGenerator.new(initial_value, decay_rate)
  reward = RewardCalculator.new(base_reward, decay_factor)
  simulation = Simulation.new(sequence, reward)
  simulation.run
end

main