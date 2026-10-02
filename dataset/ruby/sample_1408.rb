require 'matrix'

class RewardDecay

    def initialize(initial_reward, decay_rate)
        @current_reward = initial_reward
        @decay_rate = decay_rate
    end

    def update_reward
        @current_reward *= 1 - @decay_rate
    end

    def get_current_reward
        @current_reward
    end
end

class Agent

    def initialize(reward_decay)
        @reward_decay = reward_decay
        @action_count = 0
    end

    def take_action
        @action_count += 1
        @reward_decay.update_reward
    end

    def get_reward
        @reward_decay.get_current_reward
    end
end

def simulate_environment(agent, max_actions)
    rewards = []
    max_actions.times do
        agent.take_action
        rewards << agent.get_reward
    end
    rewards
end

def main
    initial_reward = 1.0
    decay_rate = 0.01
    max_actions = 1000
    reward_decay = RewardDecay.new(initial_reward, decay_rate)
    agent = Agent.new(reward_decay)
    rewards = simulate_environment(agent, max_actions)
    puts rewards.inspect
end

main if __FILE__ == $0