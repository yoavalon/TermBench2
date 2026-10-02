<?php

class Swarm {
    public $size;
    public $dimensions;
    public $bounds;
    public $particles;
    public $gbest;

    public function __construct($size, $dimensions, $bounds) {
        $this->size = $size;
        $this->dimensions = $dimensions;
        $this->bounds = $bounds;
        $this->particles = array();
        for ($i = 0; $i < $size; $i++) {
            $this->particles[] = new Particle($dimensions, $bounds);
        }
        $this->gbest = null;
    }

    public function update_gbest() {
        foreach ($this->particles as $particle) {
            if ($this->gbest === null || $particle->fitness < $this->gbest->fitness) {
                $this->gbest = $particle;
            }
        }
    }

    public function update_particles() {
        foreach ($this->particles as $particle) {
            $particle->update_velocity($this->gbest);
            $particle->update_position();
        }
    }
}

class Particle {
    public $position;
    public $velocity;
    public $best_position;
    public $fitness;

    public function __construct($dimensions, $bounds) {
        $this->position = array();
        $this->velocity = array();
        for ($i = 0; $i < $dimensions; $i++) {
            $this->position[] = mt_rand() / mt_getrandmax() * ($bounds[1] - $bounds[0]) + $bounds[0];
            $this->velocity[] = mt_rand() / mt_getrandmax() * 2 - 1;
        }
        $this->best_position = $this->position;
        $this->fitness = INF;
    }

    public function update_velocity($gbest) {
        $w = 0.5;
        $c1 = 1.5;
        $c2 = 1.5;
        for ($i = 0; $i < count($this->velocity); $i++) {
            $r1 = mt_rand() / mt_getrandmax();
            $r2 = mt_rand() / mt_getrandmax();
            $cognitive = $c1 * $r1 * ($this->best_position[$i] - $this->position[$i]);
            $social = $c2 * $r2 * ($gbest->position[$i] - $this->position[$i]);
            $this->velocity[$i] = $w * $this->velocity[$i] + $cognitive + $social;
        }
    }

    public function update_position() {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
            if ($this->position[$i] < $this->bounds[0]) {
                $this->position[$i] = $this->bounds[0];
            }
            if ($this->position[$i] > $this->bounds[1]) {
                $this->position[$i] = $this->bounds[1];
            }
        }
    }
}

function objective_function($x) {
    $sum = 0;
    foreach ($x as $xi) {
        $sum += $xi ** 2;
    }
    return $sum;
}

function optimize($swarm, $max_iterations) {
    for ($i = 0; $i < $max_iterations; $i++) {
        $swarm->update_gbest();
        foreach ($swarm->particles as $particle) {
            $particle->fitness = objective_function($particle->position);
        }
        $swarm->update_particles();
    }
}

function main() {
    $size = 30;
    $dimensions = 2;
    $bounds = array(-10, 10);
    $max_iterations = 100;
    $swarm = new Swarm($size, $dimensions, $bounds);
    optimize($swarm, $max_iterations);
    print_r($swarm->gbest->position);
}

main();

?>