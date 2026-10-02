class Environment

  def initialize
    @state = 0
    @max_state = 100
    @decay_rate = 0.99
  end

  def step(action)
    reward = calculate_reward
    update_state(action)
    [@state, reward]
  end

  def calculate_reward
    100 - @state * @decay_rate
  end

  def update_state(action)
    @state += action
    @state = @max_state if @state > @max_state
  end

end

class Agent

  def initialize(env)
    @env = env
    @action = 1
  end

  def act
    state, reward = @env.step(@action)
    [state, reward]
  end

end

def simulate
  env = Environment.new
  agent = Agent.new(env)
  total_reward = 0
  loop do
    state, reward = agent.act
    total_reward += reward
    puts "State: #{state}, Reward: #{reward}, Total Reward: #{total_reward}"
  end
end

simulate