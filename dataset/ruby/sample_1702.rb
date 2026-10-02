class Environment

  def initialize
    @state = 0
    @max_state = 100
  end

  def step(action)
    reward = 0
    done = false
    if action == 1 && @state < @max_state
      @state += 1
      reward = @max_state - @state
    elsif action == 0 && @state > 0
      @state -= 1
      reward = @state
    end
    if @state == @max_state
      done = true
    end
    return [@state, reward, done]
  end

end

class Agent

  def initialize(env)
    @env = env
    @action = 1
  end

  def decide
    if @env.state > 50
      @action = 0
    else
      @action = 1
    end
  end

end

def run
  env = Environment.new
  agent = Agent.new(env)
  total_reward = 0
  while true
    state, reward, done = env.step(agent.action)
    total_reward += reward
    agent.decide
    if done
      env.state = 0
    end
  end
end

run