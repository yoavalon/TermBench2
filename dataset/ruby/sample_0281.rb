class Environment
  attr_accessor :current, :goal, :decay_rate, :time_step

  def initialize(start, goal, decay_rate)
    @current = start
    @goal = goal
    @decay_rate = decay_rate
    @time_step = 0
  end

  def step(action)
    @current += action
    @time_step += 1
    reward = compute_reward
    done = is_done
    [current, reward, done]
  end

  def compute_reward
    distance = (@current - @goal).abs
    reward = 1.0 / (distance + 1)
    reward *= (1 - @decay_rate) ** @time_step
    reward
  end

  def is_done
    @current == @goal || @time_step > 1000
  end
end

class Agent
  attr_accessor :action_space

  def initialize(action_space)
    @action_space = action_space
  end

  def act(observation)
    @action_space.rand
  end
end

def run_episode(env, agent)
  observation = env.current
  total_reward = 0
  done = false
  while !done
    action = agent.act(observation)
    observation, reward, done = env.step(action)
    total_reward += reward
  end
  total_reward
end

def main
  require 'random'
  Random.srand(42)
  env = Environment.new(0, 10, 0.01)
  agent = Agent.new(Random.new(42))
  episode_reward = run_episode(env, agent)
  puts "Episode reward: #{episode_reward}"
end

main if __FILE__ == $0