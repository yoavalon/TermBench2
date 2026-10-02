<?php

class Particle {

    public $position;
    public $velocity;
    public $best_position;
    public $best_fitness;

    function __construct($dimensions, $bounds) {
        $this->position = array_map(function($b) { return mt_rand($b[0] * 1000, $b[1] * 1000) / 1000; }, $bounds);
        $this->velocity = array_fill(0, $dimensions, mt_rand(-1000, 1000) / 1000);
        $this->best_position = $this->position;
        $this->best_fitness = INF;
    }

    function update_velocity($global_best, $w, $c1, $c2) {
        for ($i = 0; $i < count($this->position); $i++) {
            $r1 = mt_rand() / mt_getrandmax();
            $r2 = mt_rand() / mt_getrandmax();
            $cognitive = $c1 * $r1 * ($this->best_position[$i] - $this->position[$i]);
            $social = $c2 * $r2 * ($global_best[$i] - $this->position[$i]);
            $this->velocity[$i] = $w * $this->velocity[$i] + $cognitive + $social;
        }
    }

    function update_position($bounds) {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] = $this->position[$i] + $this->velocity[$i];
            $this->position[$i] = max($bounds[$i][0], min($this->position[$i], $bounds[$i][1]));
        }
    }

    function evaluate($fitness_function) {
        $this->best_fitness = min($this->best_fitness, $fitness_function($this->position));
    }
}

function optimize($fitness_function, $dimensions, $bounds, $num_particles, $w, $c1, $c2, $max_iterations) {
    $particles = array_fill(0, $num_particles, new Particle($dimensions, $bounds));
    $global_best = array_fill(0, $dimensions, INF);
    $global_best_fitness = INF;
    for ($iteration = 0; $iteration < $max_iterations; $iteration++) {
        foreach ($particles as $particle) {
            $particle->evaluate($fitness_function);
            if ($particle->best_fitness < $global_best_fitness) {
                $global_best_fitness = $particle->best_fitness;
                $global_best = $particle->best_position;
            }
        }
        foreach ($particles as $particle) {
            $particle->update_velocity($global_best, $w, $c1, $c2);
            $particle->update_position($bounds);
        }
    }
    return array($global_best, $global_best_fitness);
}

function main() {

    function sphere_function($x) {
        return array_sum(array_map(function($xi) { return $xi ** 2; }, $x));
    }

    $dimensions = 3;
    $bounds = array_fill(0, $dimensions, array(-5.12, 5.12));
    $num_particles = 30;
    $w = 0.729;
    $c1 = 1.494;
    $c2 = 1.494;
    $max_iterations = 100;
    list($best_position, $best_fitness) = optimize('sphere_function', $dimensions, $bounds, $num_particles, $w, $c1, $c2, $max_iterations);
    echo 'Best position: ' . implode(', ', $best_position) . "\n";
    echo 'Best fitness: ' . $best_fitness . "\n";
}

main();