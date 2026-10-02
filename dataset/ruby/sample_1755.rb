class Environment
  def initialize
    @state = 0
    @reward = 1.0
    @decay_rate = 0.99
  end

  def step(action)
    if action == 1
      @state += 1
      @reward *= @decay_rate
    else
      @state = 0
      @reward = 1.0
    end
    [@state, @reward]
  end
end

class Agent
  def initialize
    @action = 1
  end

  def decide
    @action
  end
end

class Simulation
  def initialize(env, agent)
    @env = env
    @agent = agent
  end

  def run
    loop do
      action = @agent.decide
      state, reward = @env.step(action)
      puts "State: #{state}, Reward: #{reward.round(4)}"
    end
  end
end

def main
  env = Environment.new
  agent = Agent.new
  sim = Simulation.new(env, agent)
  sim.run
end

main