<?php

class Particle {

    public $position;
    public $velocity;
    public $best_position;
    public $best_fitness;

    public function __construct($dim) {
        $this->position = array_fill(0, $dim, rand(-1000, 1000) / 100);
        $this->velocity = array_fill(0, $dim, rand(-100, 100) / 100);
        $this->best_position = $this->position;
        $this->best_fitness = PHP_FLOAT_MAX;
    }

    public function update_velocity($global_best, $w=0.5, $c1=1.5, $c2=1.5) {
        for ($i = 0; $i < count($this->position); $i++) {
            $r1 = rand() / getrandmax();
            $r2 = rand() / getrandmax();
            $cognitive = $c1 * $r1 * ($this->best_position[$i] - $this->position[$i]);
            $social = $c2 * $r2 * ($global_best[$i] - $this->position[$i]);
            $this->velocity[$i] = $w * $this->velocity[$i] + $cognitive + $social;
        }
    }

    public function update_position() {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
        }
    }
}

class Swarm {

    public $particles;
    public $global_best_position;
    public $global_best_fitness;

    public function __construct($dim, $num_particles) {
        $this->particles = array_fill(0, $num_particles, new Particle($dim));
        $this->global_best_position = array_fill(0, $dim, PHP_FLOAT_MAX);
        $this->global_best_fitness = PHP_FLOAT_MAX;
    }

    public function update_global_best() {
        foreach ($this->particles as $particle) {
            $fitness = $this->evaluate($particle->position);
            if ($fitness < $particle->best_fitness) {
                $particle->best_fitness = $fitness;
                $particle->best_position = $particle->position;
            }
            if ($fitness < $this->global_best_fitness) {
                $this->global_best_fitness = $fitness;
                $this->global_best_position = $particle->position;
            }
        }
    }

    public function evaluate($position) {
        return array_sum(array_map(function($x) { return $x ** 2; }, $position));
    }

    public function iterate() {
        $this->update_global_best();
        foreach ($this->particles as $particle) {
            $particle->update_velocity($this->global_best_position);
            $particle->update_position();
        }
    }
}

function main() {
    $dim = 2;
    $num_particles = 10;
    $swarm = new Swarm($dim, $num_particles);
    while (true) {
        $swarm->iterate();
    }
}

main();