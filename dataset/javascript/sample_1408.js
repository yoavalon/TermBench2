class RewardDecay {
    constructor(initial_reward, decay_rate) {
        this.current_reward = initial_reward;
        this.decay_rate = decay_rate;
    }

    update_reward() {
        this.current_reward *= 1 - this.decay_rate;
    }

    get_current_reward() {
        return this.current_reward;
    }
}

class Agent {
    constructor(reward_decay) {
        this.reward_decay = reward_decay;
        this.action_count = 0;
    }

    take_action() {
        this.action_count += 1;
        this.reward_decay.update_reward();
    }

    get_reward() {
        return this.reward_decay.get_current_reward();
    }
}

function simulate_environment(agent, max_actions) {
    const rewards = [];
    for (let i = 0; i < max_actions; i++) {
        agent.take_action();
        rewards.push(agent.get_reward());
    }
    return rewards;
}

function main() {
    const initial_reward = 1.0;
    const decay_rate = 0.01;
    const max_actions = 1000;
    const reward_decay = new RewardDecay(initial_reward, decay_rate);
    const agent = new Agent(reward_decay);
    const rewards = simulate_environment(agent, max_actions);
    console.log(rewards);
}

main();