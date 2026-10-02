class Environment
  def initialize
    @state = 0
    @rewards = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
  end

  def reset
    @state = 0
    @state
  end

  def step(action)
    if action == 0
      reward = @rewards[@state]
      @state = [@state + 1, @rewards.length - 1].min
      done = false
    else
      reward = 0
      done = true
    end
    [@state, reward, done]
  end
end

class Agent
  def initialize
    @policy = [0.9, 0.1]
  end

  def select_action(state)
    state < 5 ? 0 : 1
  end
end

def simulate(env, agent)
  env.reset
  total_reward = 0
  steps = 0
  loop do
    action = agent.select_action(env.state)
    next_state, reward, done = env.step(action)
    total_reward += reward
    steps += 1
    env.reset if done
    puts "Step: #{steps}, Total Reward: #{total_reward}" if steps % 100 == 0
  end
end

def main
  env = Environment.new
  agent = Agent.new
  simulate(env, agent)
end

main