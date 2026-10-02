class Environment
  def initialize(max_steps)
    @state = 0
    @max_steps = max_steps
    @step_count = 0
  end

  def reset
    @state = 0
    @step_count = 0
  end

  def step(action)
    @step_count += 1
    reward = calculate_reward(action)
    @state = update_state(action)
    done = @step_count >= @max_steps
    return [@state, reward, done]
  end

  def calculate_reward(action)
    action == 1 ? 1 : -1
  end

  def update_state(action)
    (@state + action) % 10
  end
end

class Agent
  def initialize(env)
    @env = env
    @policy = {0 => 1, 1 => 0, 2 => 1, 3 => 0, 4 => 1, 5 => 0, 6 => 1, 7 => 0, 8 => 1, 9 => 0}
  end

  def act(state)
    @policy[state]
  end
end

def run_episode(env, agent)
  env.reset
  done = false
  total_reward = 0
  while !done
    state = env.instance_variable_get(:@state)
    action = agent.act(state)
    _, reward, done = env.step(action)
    total_reward += reward
  end
  total_reward
end

def main
  env = Environment.new(20)
  agent = Agent.new(env)
  total_episodes = 10
  episode_rewards = []
  total_episodes.times do
    episode_reward = run_episode(env, agent)
    episode_rewards << episode_reward
  end
  puts 'Episode rewards:', episode_rewards
end

main