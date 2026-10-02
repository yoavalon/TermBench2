<?php

class Particle {
    public $position;
    public $velocity;
    public $best_position;
    public $best_fitness;

    function __construct($dimensions, $lower_bound, $upper_bound) {
        $this->position = array_fill(0, $dimensions, 0);
        $this->velocity = array_fill(0, $dimensions, 0);
        for ($i = 0; $i < $dimensions; $i++) {
            $this->position[$i] = mt_rand() / mt_getrandmax() * ($upper_bound - $lower_bound) + $lower_bound;
            $this->velocity[$i] = mt_rand() / mt_getrandmax() * 2 - 1;
        }
        $this->best_position = $this->position;
        $this->best_fitness = INF;
    }

    function update_velocity($global_best_position, $w, $c1, $c2) {
        for ($i = 0; $i < count($this->position); $i++) {
            $r1 = mt_rand() / mt_getrandmax();
            $r2 = mt_rand() / mt_getrandmax();
            $cognitive_velocity = $c1 * $r1 * ($this->best_position[$i] - $this->position[$i]);
            $social_velocity = $c2 * $r2 * ($global_best_position[$i] - $this->position[$i]);
            $this->velocity[$i] = $w * $this->velocity[$i] + $cognitive_velocity + $social_velocity;
        }
    }

    function update_position($lower_bound, $upper_bound) {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
            $this->position[$i] = max($lower_bound, min($upper_bound, $this->position[$i]));
        }
    }
}

class Swarm {
    public $particles;
    public $global_best_position;
    public $global_best_fitness;

    function __construct($num_particles, $dimensions, $lower_bound, $upper_bound) {
        $this->particles = array_fill(0, $num_particles, new Particle($dimensions, $lower_bound, $upper_bound));
        $this->global_best_position = array_fill(0, $dimensions, 0);
        for ($i = 0; $i < $dimensions; $i++) {
            $this->global_best_position[$i] = mt_rand() / mt_getrandmax() * ($upper_bound - $lower_bound) + $lower_bound;
        }
        $this->global_best_fitness = INF;
    }

    function evaluate_fitness($objective_function) {
        foreach ($this->particles as $particle) {
            $fitness = $objective_function($particle->position);
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

    function update_particles($w, $c1, $c2) {
        foreach ($this->particles as $particle) {
            $particle->update_velocity($this->global_best_position, $w, $c1, $c2);
            $particle->update_position(-10, 10);
        }
    }
}

function objective_function($x) {
    $sum = 0;
    for ($i = 0; $i < count($x); $i++) {
        $sum += sin($x[$i]) * sin($x[$i] + ($i + 1) * pi() / count($x));
    }
    return $sum;
}

function main() {
    $num_particles = 30;
    $dimensions = 30;
    $lower_bound = -10;
    $upper_bound = 10;
    $w = 0.729;
    $c1 = 1.494;
    $c2 = 1.494;
    $swarm = new Swarm($num_particles, $dimensions, $lower_bound, $upper_bound);
    while (true) {
        $swarm->evaluate_fitness('objective_function');
        $swarm->update_particles($w, $c1, $c2);
    }
}

main();