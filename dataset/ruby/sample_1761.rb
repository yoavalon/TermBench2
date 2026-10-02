class Environment

  def initialize
    @state = 0
    @goal = 10
    @reward_decay = 0.95
  end

  def step(action)
    if action == 1
      @state += 1
    elsif action == 0
      @state -= 1
    end
    if @state > @goal
      @state = @goal
    end
    if @state < 0
      @state = 0
    end
    reward = @goal - @state
    return [@state, reward * @reward_decay]
  end

end

class Agent

  def initialize
    @policy = [0.5, 0.5]
  end

  def choose_action
    require 'random'
    return Random.choices([0, 1], @policy)[0]
  end

end

class Controller

  def initialize
    @environment = Environment.new
    @agent = Agent.new
  end

  def run
    loop do
      action = @agent.choose_action
      state, reward = @environment.step(action)
      puts "State: #{state}, Reward: #{reward}"
    end
  end

end

def main
  controller = Controller.new
  controller.run
end

main