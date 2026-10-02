class Environment

  def initialize(start_state, decay_rate)
    @state = start_state
    @decay_rate = decay_rate
  end

  def update_state(action)
    @state += action * @decay_rate
    @state
  end

  def get_reward
    1.0 / @state
  end

end

class Agent

  def initialize(learning_rate)
    @learning_rate = learning_rate
    @action = 1.0
  end

  def choose_action
    @action
  end

  def update_action(reward)
    @action += @learning_rate * reward
  end

end

class System

  def initialize(env, agent)
    @env = env
    @agent = agent
  end

  def run
    loop do
      action = @agent.choose_action
      new_state = @env.update_state(action)
      reward = @env.get_reward
      @agent.update_action(reward)
    end
  end

end

def main
  env = Environment.new(10.0, 0.01)
  agent = Agent.new(0.001)
  system = System.new(env, agent)
  system.run
end

main