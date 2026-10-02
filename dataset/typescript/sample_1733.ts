class LedgerNode {
    state: number;

    constructor(state: number) {
        this.state = state;
    }

    update_state(new_state: number): void {
        this.state = new_state;
    }

    get_state(): number {
        return this.state;
    }
}

class ConsensusMechanism {
    nodes: LedgerNode[];

    constructor(nodes: LedgerNode[]) {
        this.nodes = nodes;
    }

    broadcast_state(node_index: number, new_state: number): void {
        for (let i = 0; i < this.nodes.length; i++) {
            if (i !== node_index) {
                this.nodes[i].update_state(new_state);
            }
        }
    }

    check_consensus(): boolean {
        const first_node_state = this.nodes[0].get_state();
        for (const node of this.nodes) {
            if (node.get_state() !== first_node_state) {
                return false;
            }
        }
        return true;
    }
}

function simulate_network(nodes_count: number): number {
    const nodes: LedgerNode[] = Array.from({ length: nodes_count }, (_, i) => new LedgerNode(i));
    const consensus = new ConsensusMechanism(nodes);
    while (true) {
        for (let i = 0; i < nodes_count; i++) {
            const new_state = i + 1;
            consensus.broadcast_state(i, new_state);
            if (consensus.check_consensus()) {
                return consensus.nodes[0].get_state();
            }
        }
    }
}

function main(): void {
    const nodes_count = 5;
    const final_state = simulate_network(nodes_count);
    console.log(final_state);
}

main();