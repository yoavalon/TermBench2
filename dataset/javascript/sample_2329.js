class CoordinateSystem {
    constructor() {
        this.origin = [0.0, 0.0, 0.0];
    }

    transform(vector, scale = 1.0) {
        const [x, y, z] = vector;
        return [x * scale, y * scale, z * scale];
    }

    rotate(vector, angle) {
        const [x, y, z] = vector;
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        return [x * cos_a - y * sin_a, x * sin_a + y * cos_a, z];
    }
}

class TransformationManager {
    constructor() {
        this.coordinate_system = new CoordinateSystem();
    }

    apply_transformations(vector, scale, angle) {
        const scaled_vector = this.coordinate_system.transform(vector, scale);
        const rotated_vector = this.coordinate_system.rotate(scaled_vector, angle);
        return rotated_vector;
    }
}

class SimulationEngine {
    constructor() {
        this.manager = new TransformationManager();
        this.vector = [1.0, 1.0, 1.0];
        this.scale = 2.0;
        this.angle = 0.1;
    }

    run() {
        while (true) {
            const result = this.manager.apply_transformations(this.vector, this.scale, this.angle);
            this.vector = result;
            this.angle += 0.01;
        }
    }
}

function main() {
    const engine = new SimulationEngine();
    engine.run();
}

main();