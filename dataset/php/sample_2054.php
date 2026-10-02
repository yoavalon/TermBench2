<?php

class Particle {

    function __construct($dimensions) {
        $this->position = array_map(function() { return rand(-1, 1) / 1.0; }, range(0, $dimensions - 1));
        $this->velocity = array_map(function() { return rand(-1, 1) / 1.0; }, range(0, $dimensions - 1));
        $this->best_position = $this->position;
        $this->best_value = PHP_FLOAT_MAX;
    }

    function update_velocity($global_best, $w = 0.7, $c1 = 1.5, $c2 = 1.5) {
        for ($i = 0; $i < count($this->position); $i++) {
            $r1 = rand() / getrandmax();
            $r2 = rand() / getrandmax();
            $cognitive = $c1 * $r1 * ($this->best_position[$i] - $this->position[$i]);
            $social = $c2 * $r2 * ($global_best[$i] - $this->position[$i]);
            $this->velocity[$i] = $w * $this->velocity[$i] + $cognitive + $social;
        }
    }

    function update_position() {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
        }
    }

    function evaluate($objective_function) {
        $this->best_value = $objective_function($this->position);
        if ($this->best_value < $this->best_value) {
            $this->best_position = $this->position;
        }
    }
}

class Swarm {

    function __construct($dimensions, $num_particles) {
        $this->particles = array_map(function() use ($dimensions) { return new Particle($dimensions); }, range(0, $num_particles - 1));
        $this->global_best = array_fill(0, $dimensions, PHP_FLOAT_MAX);
        $this->global_best_value = PHP_FLOAT_MAX;
    }

    function update_global_best() {
        foreach ($this->particles as $particle) {
            if ($particle->best_value < $this->global_best_value) {
                $this->global_best_value = $particle->best_value;
                $this->global_best = $particle->best_position;
            }
        }
    }

    function iterate($objective_function) {
        foreach ($this->particles as $particle) {
            $particle->update_velocity($this->global_best);
            $particle->update_position();
            $particle->evaluate($objective_function);
        }
        $this->update_global_best();
    }
}

function objective_function($x) {
    return array_sum(array_map(function($xi) { return $xi ** 2; }, $x));
}

function optimize($dimensions, $num_particles, $max_iterations) {
    $swarm = new Swarm($dimensions, $num_particles);
    for ($i = 0; $i < $max_iterations; $i++) {
        $swarm->iterate('objective_function');
    }
    return $swarm->global_best;
}

function main() {
    $dimensions = 10;
    $num_particles = 20;
    $max_iterations = 100;
    $best_solution = optimize($dimensions, $num_particles, $max_iterations);
    echo 'Best solution: ' . implode(', ', $best_solution) . "\n";
}

main();