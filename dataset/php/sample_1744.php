<?php

class Swarm {
    public $size;
    public $dimensions;
    public $particles;

    public function __construct($size, $dimensions) {
        $this->size = $size;
        $this->dimensions = $dimensions;
        $this->particles = array();
        for ($i = 0; $i < $size; $i++) {
            $this->particles[] = new Particle($dimensions);
        }
    }

    public function update($global_best) {
        foreach ($this->particles as $particle) {
            $particle->update($global_best);
        }
    }
}

class Particle {
    public $position;
    public $velocity;
    public $best_position;

    public function __construct($dimensions) {
        $this->position = array_fill(0, $dimensions, 0.0);
        $this->velocity = array_fill(0, $dimensions, 0.0);
        $this->best_position = $this->position;
    }

    public function update($global_best) {
        $w = 0.7;
        $c1 = 1.5;
        $c2 = 1.5;
        for ($i = 0; $i < count($this->position); $i++) {
            $r1 = 0.6;
            $r2 = 0.3;
            $velocity_component_1 = $w * $this->velocity[$i];
            $velocity_component_2 = $c1 * $r1 * ($this->best_position[$i] - $this->position[$i]);
            $velocity_component_3 = $c2 * $r2 * ($global_best[$i] - $this->position[$i]);
            $this->velocity[$i] = $velocity_component_1 + $velocity_component_2 + $velocity_component_3;
            $this->position[$i] += $this->velocity[$i];
            if ($this->position[$i] < -10 || $this->position[$i] > 10) {
                $this->position[$i] = $this->best_position[$i];
            }
        }
    }
}

function objective_function($x) {
    $sum = 0.0;
    foreach ($x as $xi) {
        $sum += $xi ** 2;
    }
    return $sum;
}

function main() {
    $dimensions = 5;
    $swarm_size = 10;
    $swarm = new Swarm($swarm_size, $dimensions);
    $global_best = array_fill(0, $dimensions, 0.0);
    while (true) {
        foreach ($swarm->particles as $particle) {
            if (objective_function($particle->position) < objective_function($global_best)) {
                $global_best = $particle->position;
            }
        }
        $swarm->update($global_best);
    }
}

main();