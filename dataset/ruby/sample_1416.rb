require 'matrix'

class Environment

  def initialize(size)
    @state = Vector.build(size) { 0 }
  end

  def reset
    @state = Vector.build(@state.size) { 0 }
    @state
  end

  def step(action)
    reward = randn
    @state[action] += 1
    done = false
    if @state.any? { |s| s > 10 }
      done = true
    end
    [@state, reward, done]
  end

end

class Agent

  def initialize(action_space)
    @action_space = action_space
  end

  def choose_action
    @action_space.sample
  end

end

def train_agent(env, agent, episodes, decay_rate)
  rewards = []
  episodes.times do |episode|
    state = env.reset
    total_reward = 0
    100.times do
      action = agent.choose_action
      state, reward, done = env.step(action)
      total_reward += reward
      break if done
    end
    rewards << total_reward
    if episode > 0 && episode % 10 == 0
      rewards = rewards.map { |r| r * decay_rate }
    end
  end
  rewards
end

def main
  env_size = 5
  action_space = (0...env_size).to_a
  env = Environment.new(env_size)
  agent = Agent.new(action_space)
  episodes = 50
  decay_rate = 0.9
  train_agent(env, agent, episodes, decay_rate)
end

main