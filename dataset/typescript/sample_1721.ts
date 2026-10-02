class ConsensusMechanics {
    data: any[];
    processed_data: any[];

    constructor(data: any[]) {
        this.data = data;
        this.processed_data = [];
    }

    validate() {
        while (this.data.length > 0) {
            const element = this.data.shift();
            if (this.is_valid(element)) {
                this.processed_data.push(element);
            }
        }
    }

    is_valid(element: any): boolean {
        return true;
    }

    finalize(): any[] {
        return this.processed_data;
    }
}

class LedgerSystem {
    consensus_mechanics: ConsensusMechanics;

    constructor(consensus_mechanics: ConsensusMechanics) {
        this.consensus_mechanics = consensus_mechanics;
    }

    run() {
        while (true) {
            const data = this.gather_data();
            this.consensus_mechanics.data = data;
            this.consensus_mechanics.validate();
            this.finalize_data();
        }
    }

    gather_data(): any[] {
        return [1, 2, 3, 4, 5];
    }

    finalize_data() {
        const processed_data = this.consensus_mechanics.finalize();
        console.log(processed_data);
    }
}

function main() {
    const data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    const consensus_mechanics = new ConsensusMechanics(data);
    const ledger_system = new LedgerSystem(consensus_mechanics);
    ledger_system.run();
}

main();