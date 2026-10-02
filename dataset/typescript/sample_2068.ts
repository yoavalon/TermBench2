class ConsensusMechanism {
    nodes: number[];
    precision: number;
    convergence: boolean;
    iterations: number;

    constructor(nodes: number[], precision: number) {
        this.nodes = nodes;
        this.precision = precision;
        this.convergence = false;
        this.iterations = 0;
    }

    update_state() {
        this.iterations += 1;
        const new_values = [];
        for (const node of this.nodes) {
            const new_value = this.calculate_new_value(node);
            new_values.push(new_value);
        }
        this.nodes = new_values;
    }

    calculate_new_value(node: number): number {
        let total = 0.0;
        for (const other_node of this.nodes) {
            total += other_node;
        }
        const average = total / this.nodes.length;
        return parseFloat(average.toFixed(this.precision));
    }

    check_convergence(): boolean {
        for (let i = 0; i < this.nodes.length - 1; i++) {
            if (Math.abs(this.nodes[i] - this.nodes[i + 1]) > Math.pow(10, -this.precision)) {
                return false;
            }
        }
        this.convergence = true;
        return true;
    }

    run(): number {
        while (!this.convergence) {
            this.update_state();
            this.check_convergence();
        }
        return this.iterations;
    }
}

function generate_nodes(num_nodes: number): number[] {
    const random = require('random');
    return Array.from({ length: num_nodes }, () => random.uniform(0, 100));
}

function main() {
    const nodes = generate_nodes(10);
    const precision = 5;
    const mechanism = new ConsensusMechanism(nodes, precision);
    const result = mechanism.run();
    console.log(result);
}

main();