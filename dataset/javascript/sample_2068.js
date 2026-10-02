class ConsensusMechanism {
    constructor(nodes, precision) {
        this.nodes = nodes;
        this.precision = precision;
        this.convergence = false;
        this.iterations = 0;
    }

    update_state() {
        this.iterations += 1;
        let new_values = [];
        for (let node of this.nodes) {
            let new_value = this.calculate_new_value(node);
            new_values.push(new_value);
        }
        this.nodes = new_values;
    }

    calculate_new_value(node) {
        let total = 0.0;
        for (let other_node of this.nodes) {
            total += other_node;
        }
        let average = total / this.nodes.length;
        return parseFloat(average.toFixed(this.precision));
    }

    check_convergence() {
        for (let i = 0; i < this.nodes.length - 1; i++) {
            if (Math.abs(this.nodes[i] - this.nodes[i + 1]) > Math.pow(10, -this.precision)) {
                return false;
            }
        }
        this.convergence = true;
        return true;
    }

    run() {
        while (!this.convergence) {
            this.update_state();
            this.check_convergence();
        }
        return this.iterations;
    }
}

function generate_nodes(num_nodes) {
    let nodes = [];
    for (let i = 0; i < num_nodes; i++) {
        nodes.push(Math.random() * 100);
    }
    return nodes;
}

function main() {
    let nodes = generate_nodes(10);
    let precision = 5;
    let mechanism = new ConsensusMechanism(nodes, precision);
    let result = mechanism.run();
    console.log(result);
}

main();