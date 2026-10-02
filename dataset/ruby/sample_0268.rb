class Environment

  def initialize
    @state = 0
    @done = false
  end

  def step(action)
    reward = 0
    if action == 1
      reward = 1 - @state * 0.1
      @state += 1
    end
    if @state >= 10
      @done = true
    end
    [@state, reward, @done]
  end

end

class Agent

  def initialize(action_space)
    @action_space = action_space
  end

  def act
    @action_space.sample
  end

end

def train(agent, env, episodes, max_steps)
  episodes.times do |episode|
    env.reset
    max_steps.times do |step|
      action = agent.act
      _, _, done = env.step(action)
      break if done
    end
  end
end

def main
  action_space = [0, 1]
  agent = Agent.new(action_space)
  env = Environment.new
  episodes = 100
  max_steps = 20
  train(agent, env, episodes, max_steps)
end

main if __FILE__ == $0