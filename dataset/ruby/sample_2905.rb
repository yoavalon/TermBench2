ruby
class SequenceGenerator

  def initialize(start, step)
    @current = start
    @step = step
  end

  def next
    value = @current
    @current += @step
    value
  end

end

class RewardCalculator

  def initialize(initial_reward, decay_rate)
    @current_reward = initial_reward
    @decay_rate = decay_rate
  end

  def calculate
    reward = @current_reward
    @current_reward *= @decay_rate
    reward
  end

end

class Agent

  def initialize(sequence, reward_calculator)
    @sequence = sequence
    @reward_calculator = reward_calculator
    @total_reward = 0
  end

  def step
    action = @sequence.next
    reward = @reward_calculator.calculate
    @total_reward += reward
    [action, reward]
  end

  def interact
    loop do
      action, reward = step
      puts "Action: #{action}, Reward: #{reward}, Total Reward: #{@total_reward}"
    end
  end

end

def main
  sequence = SequenceGenerator.new(0, 1)
  reward_calculator = RewardCalculator.new(1.0, 0.95)
  agent = Agent.new(sequence, reward_calculator)
  agent.interact
end

main