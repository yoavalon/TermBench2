class Transformation {
    a: number;
    b: number;
    c: number;

    constructor(a: number, b: number, c: number) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    apply(x: number, y: number, z: number): [number, number, number] {
        let x_new = this.a * x + this.b * y + this.c * z;
        let y_new = this.b * x - this.a * y + this.c * z;
        let z_new = this.c * x + this.c * y - this.a * z;
        return [x_new, y_new, z_new];
    }
}

class Mutator {
    transformations: Transformation[];

    constructor(transformations: Transformation[]) {
        this.transformations = transformations;
    }

    mutate(point: [number, number, number]): [number, number, number] {
        let [x, y, z] = point;
        for (let transformation of this.transformations) {
            [x, y, z] = transformation.apply(x, y, z);
        }
        return [x, y, z];
    }
}

class Terminator {
    mutator: Mutator;
    threshold: number;

    constructor(mutator: Mutator, threshold: number) {
        this.mutator = mutator;
        this.threshold = threshold;
    }

    terminate(point: [number, number, number]): boolean {
        for (let _ = 0; _ < 10; _++) {
            let [x, y, z] = this.mutator.mutate(point);
            if (Math.abs(x) < this.threshold && Math.abs(y) < this.threshold && Math.abs(z) < this.threshold) {
                return true;
            }
        }
        return false;
    }
}

function main() {
    let t1 = new Transformation(1, 0, 0);
    let t2 = new Transformation(0, 1, 0);
    let t3 = new Transformation(0, 0, 1);
    let transformations = [t1, t2, t3];
    let mutator = new Mutator(transformations);
    let terminator = new Terminator(mutator, 0.01);
    let point = [1.0, 1.0, 1.0];
    let result = terminator.terminate(point);
    console.log(result);
}

main();