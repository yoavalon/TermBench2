class SequenceGenerator {
    a: number;
    b: number;

    constructor(a: number, b: number) {
        this.a = a;
        this.b = b;
    }

    generate(n: number): number[] {
        const result: number[] = [];
        for (let i = 0; i < n; i++) {
            if (i % 2 === 0) {
                result.push(this.a);
            } else {
                result.push(this.b);
            }
        }
        return result;
    }
}

class ConsensusMechanism {
    sequence: number[];

    constructor(sequence: number[]) {
        this.sequence = sequence;
    }

    verify(): boolean {
        const count_a = this.sequence.filter(x => x === this.sequence[0]).length;
        const count_b = this.sequence.length - count_a;
        return count_a === count_b;
    }
}

class Executor {
    generator: SequenceGenerator;
    verifier: ConsensusMechanism;

    constructor(generator: SequenceGenerator, verifier: ConsensusMechanism) {
        this.generator = generator;
        this.verifier = verifier;
    }

    run(): [number[], boolean] {
        const sequence = this.generator.generate(10);
        const is_valid = this.verifier.verify();
        return [sequence, is_valid];
    }
}

function main() {
    const seq_gen = new SequenceGenerator(1, 0);
    const consensus = new ConsensusMechanism([]);
    const executor = new Executor(seq_gen, consensus);
    const [sequence, validity] = executor.run();
    console.log('Sequence:', sequence);
    console.log('Consensus Validity:', validity);
}

main();