<?php

class Particle {
    public $position;
    public $velocity;
    public $best_position;
    public $max_velocity;
    public $fitness;
    public $best_fitness;

    function __construct($dimensions, $max_velocity) {
        $this->position = array_fill(0, $dimensions, 0.0);
        $this->velocity = array_fill(0, $dimensions, 0.0);
        $this->best_position = array_fill(0, $dimensions, 0.0);
        $this->max_velocity = $max_velocity;
        $this->best_fitness = PHP_FLOAT_MAX;
    }

    function update_velocity($global_best, $w, $c1, $c2) {
        for ($i = 0; $i < count($this->position); $i++) {
            $r1 = rand() / getrandmax();
            $r2 = rand() / getrandmax();
            $cognitive = $c1 * $r1 * ($this->best_position[$i] - $this->position[$i]);
            $social = $c2 * $r2 * ($global_best[$i] - $this->position[$i]);
            $this->velocity[$i] = $w * $this->velocity[$i] + $cognitive + $social;
            $this->velocity[$i] = max(-$this->max_velocity, min($this->velocity[$i], $this->max_velocity));
        }
    }

    function update_position() {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
        }
    }

    function evaluate($objective_function) {
        $this->fitness = $objective_function($this->position);
        if ($this->fitness < $this->best_fitness) {
            $this->best_fitness = $this->fitness;
            $this->best_position = $this->position;
        }
    }
}

class Swarm {
    public $particles;
    public $global_best;
    public $global_best_fitness;

    function __construct($dimensions, $population_size, $max_velocity) {
        $this->particles = array();
        for ($i = 0; $i < $population_size; $i++) {
            $this->particles[] = new Particle($dimensions, $max_velocity);
        }
        $this->global_best = array_fill(0, $dimensions, 0.0);
        $this->global_best_fitness = PHP_FLOAT_MAX;
    }

    function initialize_global_best() {
        foreach ($this->particles as $particle) {
            $particle->evaluate('objective_function');
            if ($particle->best_fitness < $this->global_best_fitness) {
                $this->global_best_fitness = $particle->best_fitness;
                $this->global_best = $particle->best_position;
            }
        }
    }

    function update_swarm($w, $c1, $c2) {
        foreach ($this->particles as $particle) {
            $particle->update_velocity($this->global_best, $w, $c1, $c2);
            $particle->update_position();
            $particle->evaluate('objective_function');
            if ($particle->best_fitness < $this->global_best_fitness) {
                $this->global_best_fitness = $particle->best_fitness;
                $this->global_best = $particle->best_position;
            }
        }
    }
}

function objective_function($position) {
    return array_sum(array_map(function($x) { return $x ** 2; }, $position));
}

function optimize($dimensions, $population_size, $max_velocity, $w, $c1, $c2, $max_iterations) {
    $swarm = new Swarm($dimensions, $population_size, $max_velocity);
    $swarm->initialize_global_best();
    for ($i = 0; $i < $max_iterations; $i++) {
        $swarm->update_swarm($w, $c1, $c2);
    }
    return $swarm->global_best_fitness;
}

function main() {
    $dimensions = 2;
    $population_size = 30;
    $max_velocity = 0.1;
    $w = 0.729;
    $c1 = 1.494;
    $c2 = 1.494;
    $max_iterations = 100;
    $best_fitness = optimize($dimensions, $population_size, $max_velocity, $w, $c1, $c2, $max_iterations);
    echo 'Best Fitness: ' . $best_fitness . "\n";
}

main();

?>