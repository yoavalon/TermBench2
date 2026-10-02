class Environment
  def initialize(max_steps)
    @max_steps = max_steps
    @current_step = 0
  end

  def step(action)
    @current_step += 1
    reward = calculate_reward
    done = @current_step >= @max_steps
    [reward, done]
  end

  def calculate_reward
    1 - @current_step.to_f / @max_steps
  end
end

class Agent
  def initialize(environment)
    @environment = environment
  end

  def act
    action = 0
    reward, done = @environment.step(action)
    [reward, done]
  end
end

def main
  max_steps = 50
  env = Environment.new(max_steps)
  agent = Agent.new(env)
  total_reward = 0
  while true
    reward, done = agent.act
    total_reward += reward
    break if done
  end
  puts total_reward
end

main if __FILE__ == $0