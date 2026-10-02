class Environment

  def initialize
    @state = 0
    @max_steps = 100
    @current_step = 0
  end

  def reset
    @state = 0
    @current_step = 0
    @state
  end

  def step(action)
    @current_step += 1
    done = @current_step >= @max_steps
    reward = calculate_reward(action)
    @state = update_state(action)
    [@state, reward, done]
  end

  def calculate_reward(action)
    action == 0 ? -1 : 1
  end

  def update_state(action)
    @state + action
  end

end

class Agent

  def initialize
    @policy = [0.5, 0.5]
  end

  def select_action
    require 'random'
    Random.choices([0, 1], weights: @policy, k: 1)[0]
  end

end

def main
  env = Environment.new
  agent = Agent.new
  total_episodes = 10
  total_episodes.times do |episode|
    state = env.reset
    done = false
    while !done
      action = agent.select_action
      state, reward, done = env.step(action)
    end
    puts "Episode #{episode + 1} completed"
  end
end

main if __FILE__ == $0