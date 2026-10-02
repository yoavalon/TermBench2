import * as random from 'random-js';

class SequenceGenerator {
    current_value: number;
    step: number;
    decay_factor: number;

    constructor(start: number, step: number, decay_factor: number) {
        this.current_value = start;
        this.step = step;
        this.decay_factor = decay_factor;
    }

    generate_next(): number {
        this.current_value += this.step;
        this.step *= this.decay_factor;
        return this.current_value;
    }
}

class RewardEvaluator {
    threshold: number;

    constructor(threshold: number) {
        this.threshold = threshold;
    }

    evaluate(value: number): number {
        return Math.max(0, value - this.threshold);
    }
}

class NonTerminatingSimulation {
    sequence_gen: SequenceGenerator;
    reward_eval: RewardEvaluator;

    constructor(sequence_gen: SequenceGenerator, reward_eval: RewardEvaluator) {
        this.sequence_gen = sequence_gen;
        this.reward_eval = reward_eval;
    }

    run(): void {
        let total_reward = 0;
        while (true) {
            const next_value = this.sequence_gen.generate_next();
            const reward = this.reward_eval.evaluate(next_value);
            total_reward += reward;
            console.log(`Value: ${next_value}, Reward: ${reward}, Total Reward: ${total_reward}`);
        }
    }
}

function main(): void {
    const engine = random.engines.mt19937().autoSeed();
    const start_value = random.integer(1, 10)(engine);
    const step_size = random.real(0.5, 2.0)(engine);
    const decay_factor = random.real(0.9, 0.99)(engine);
    const threshold = random.integer(5, 15)(engine);
    const seq_gen = new SequenceGenerator(start_value, step_size, decay_factor);
    const reward_eval = new RewardEvaluator(threshold);
    const simulation = new NonTerminatingSimulation(seq_gen, reward_eval);
    simulation.run();
}

main();