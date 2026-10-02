<?php

class Particle {
    public $position;
    public $velocity;
    public $pbest;
    public $pbest_value;

    public function __construct($dim) {
        $this->position = array_fill(0, $dim, 0.0);
        $this->velocity = array_fill(0, $dim, 0.0);
        $this->pbest = array_fill(0, $dim, 0.0);
        $this->pbest_value = INF;
    }

    public function update_velocity($gbest, $w=0.7, $c1=1.5, $c2=1.5) {
        for ($i = 0; $i < count($this->position); $i++) {
            $r1 = 0.5;
            $r2 = 0.5;
            $this->velocity[$i] = $w * $this->velocity[$i] + $c1 * $r1 * ($this->pbest[$i] - $this->position[$i]) + $c2 * $r2 * ($gbest[$i] - $this->position[$i]);
        }
    }

    public function update_position($bounds) {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
            $this->position[$i] = max($bounds[$i][0], min($bounds[$i][1], $this->position[$i]));
        }
    }

    public function update_pbest($value) {
        if ($value < $this->pbest_value) {
            $this->pbest = $this->position;
            $this->pbest_value = $value;
        }
    }
}

class Swarm {
    public $particles;
    public $gbest;
    public $gbest_value;
    public $bounds;

    public function __construct($num_particles, $dim, $bounds) {
        $this->particles = array_fill(0, $num_particles, new Particle($dim));
        $this->gbest = array_fill(0, $dim, 0.0);
        $this->gbest_value = INF;
        $this->bounds = $bounds;
    }

    public function update_gbest() {
        foreach ($this->particles as $particle) {
            if ($particle->pbest_value < $this->gbest_value) {
                $this->gbest = $particle->pbest;
                $this->gbest_value = $particle->pbest_value;
            }
        }
    }

    public function iterate() {
        foreach ($this->particles as $particle) {
            $particle->update_velocity($this->gbest);
            $particle->update_position($this->bounds);
            $particle->update_pbest(objective_function($particle->position));
        }
    }
}

function objective_function($x) {
    return array_sum(array_map(function($xi) { return $xi ** 2; }, $x));
}

function optimize($num_particles, $dim, $max_iterations, $bounds) {
    $swarm = new Swarm($num_particles, $dim, $bounds);
    for ($i = 0; $i < $max_iterations; $i++) {
        $swarm->iterate();
        $swarm->update_gbest();
    }
    return array($swarm->gbest, $swarm->gbest_value);
}

function main() {
    $num_particles = 30;
    $dim = 2;
    $max_iterations = 100;
    $bounds = array_fill(0, $dim, array(-10, 10));
    list($best_position, $best_value) = optimize($num_particles, $dim, $max_iterations, $bounds);
    echo 'Best position: ' . implode(', ', $best_position) . "\n";
    echo 'Best value: ' . $best_value . "\n";
}

main();

?>