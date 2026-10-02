require 'matrix'

class Environment
  def initialize(num_states, num_actions)
    @num_states = num_states
    @num_actions = num_actions
  end

  def step(state, action)
    reward = _compute_reward(state, action)
    next_state = _transition(state, action)
    done = _is_done(next_state)
    [next_state, reward, done]
  end

  def _compute_reward(state, action)
    -Math.sqrt((state - action) ** 2)
  end

  def _transition(state, action)
    (state + action) % @num_states
  end

  def _is_done(state)
    state == 0
  end
end

class Agent
  def initialize(num_actions)
    @num_actions = num_actions
    @policy = Array.new(num_actions) { 1.0 / num_actions }
  end

  def select_action
    index = (0...@num_actions).to_a.sample(1, weights: @policy).first
    index
  end

  def update_policy(state, action, reward)
    @policy[action] = @policy[action] + 0.1 * (reward - @policy.mean)
  end
end

def main
  num_states = 10
  num_actions = 5
  max_steps = 100
  gamma = 0.99
  env = Environment.new(num_states, num_actions)
  agent = Agent.new(num_actions)
  state = rand(num_states)
  max_steps.times do |step|
    action = agent.select_action
    next_state, reward, done = env.step(state, action)
    agent.update_policy(state, action, reward)
    state = next_state
    break if done
  end
end

main if __FILE__ == $0