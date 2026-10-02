struct CoordinateSystem {
    origin: (f64, f64, f64),
}

impl CoordinateSystem {
    fn new() -> Self {
        CoordinateSystem {
            origin: (0.0, 0.0, 0.0),
        }
    }

    fn transform(&self, vector: (f64, f64, f64), scale: f64) -> (f64, f64, f64) {
        let (x, y, z) = vector;
        (x * scale, y * scale, z * scale)
    }

    fn rotate(&self, vector: (f64, f64, f64), angle: f64) -> (f64, f64, f64) {
        let (x, y, z) = vector;
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        (x * cos_a - y * sin_a, x * sin_a + y * cos_a, z)
    }
}

struct TransformationManager {
    coordinate_system: CoordinateSystem,
}

impl TransformationManager {
    fn new() -> Self {
        TransformationManager {
            coordinate_system: CoordinateSystem::new(),
        }
    }

    fn apply_transformations(&self, vector: (f64, f64, f64), scale: f64, angle: f64) -> (f64, f64, f64) {
        let scaled_vector = self.coordinate_system.transform(vector, scale);
        let rotated_vector = self.coordinate_system.rotate(scaled_vector, angle);
        rotated_vector
    }
}

struct SimulationEngine {
    manager: TransformationManager,
    vector: (f64, f64, f64),
    scale: f64,
    angle: f64,
}

impl SimulationEngine {
    fn new() -> Self {
        SimulationEngine {
            manager: TransformationManager::new(),
            vector: (1.0, 1.0, 1.0),
            scale: 2.0,
            angle: 0.1,
        }
    }

    fn run(&mut self) {
        loop {
            let result = self.manager.apply_transformations(self.vector, self.scale, self.angle);
            self.vector = result;
            self.angle += 0.01;
        }
    }
}

fn main() {
    let mut engine = SimulationEngine::new();
    engine.run();
}