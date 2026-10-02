class Environment
  def initialize
    @state = 0
    @reward = 1.0
  end

  def step(action)
    if action == 0
      @state += 1
      @reward *= 0.95
    else
      @state -= 1
      @reward *= 0.9
    end
    if @state > 10
      return [@state, 0, true]
    elsif @state < 0
      return [@state, 0, true]
    else
      return [@state, @reward, false]
    end
  end
end

class Agent
  def initialize
    @policy = [0.5, 0.5]
  end

  def choose_action
    require 'random'
    Random.choices([0, 1], weights: @policy, num: 1)[0]
  end
end

def simulate
  env = Environment.new
  agent = Agent.new
  done = false
  while not done
    action = agent.choose_action
    _, reward, done = env.step(action)
  end
  reward
end

def main
  results = []
  100.times do
    result = simulate
    results << result
  end
  puts results.sum / results.size
end

main if __FILE__ == $0