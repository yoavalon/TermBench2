<?php

class CoordinateSystem {
    function __construct() {
        $this->origin = array(0.0, 0.0, 0.0);
    }

    function transform($vector, $scale = 1.0) {
        list($x, $y, $z) = $vector;
        return array($x * $scale, $y * $scale, $z * $scale);
    }

    function rotate($vector, $angle) {
        $x = $vector[0];
        $y = $vector[1];
        $z = $vector[2];
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        return array($x * $cos_a - $y * $sin_a, $x * $sin_a + $y * $cos_a, $z);
    }
}

class TransformationManager {
    function __construct() {
        $this->coordinate_system = new CoordinateSystem();
    }

    function apply_transformations($vector, $scale, $angle) {
        $scaled_vector = $this->coordinate_system->transform($vector, $scale);
        $rotated_vector = $this->coordinate_system->rotate($scaled_vector, $angle);
        return $rotated_vector;
    }
}

class SimulationEngine {
    function __construct() {
        $this->manager = new TransformationManager();
        $this->vector = array(1.0, 1.0, 1.0);
        $this->scale = 2.0;
        $this->angle = 0.1;
    }

    function run() {
        while (true) {
            $result = $this->manager->apply_transformations($this->vector, $this->scale, $this->angle);
            $this->vector = $result;
            $this->angle += 0.01;
        }
    }
}

function main() {
    $engine = new SimulationEngine();
    $engine->run();
}

main();