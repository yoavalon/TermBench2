<?php

class Particle {
    public $position;
    public $velocity;
    public $best_position;
    public $best_fitness;

    public function __construct($dim, $lb, $ub) {
        $this->position = array_fill(0, $dim, rand($lb * 100, $ub * 100) / 100);
        $this->velocity = array_fill(0, $dim, rand(-100, 100) / 100);
        $this->best_position = $this->position;
        $this->best_fitness = INF;
    }

    public function update_velocity($global_best, $w, $c1, $c2) {
        for ($i = 0; $i < count($this->velocity); $i++) {
            $r1 = rand() / getrandmax();
            $r2 = rand() / getrandmax();
            $cognitive = $c1 * $r1 * ($this->best_position[$i] - $this->position[$i]);
            $social = $c2 * $r2 * ($global_best[$i] - $this->position[$i]);
            $this->velocity[$i] = $w * $this->velocity[$i] + $cognitive + $social;
        }
    }

    public function update_position($lb, $ub) {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
            if ($this->position[$i] < $lb) {
                $this->position[$i] = $lb;
            }
            if ($this->position[$i] > $ub) {
                $this->position[$i] = $ub;
            }
        }
    }
}

function fitness_function($x) {
    return array_sum(array_map(function($xi) { return $xi ** 2; }, $x));
}

function optimize($dim, $lb, $ub, $num_particles, $w, $c1, $c2, $max_iter) {
    $particles = array_fill(0, $num_particles, new Particle($dim, $lb, $ub));
    $global_best = array_fill(0, $dim, INF);
    $global_best_fitness = INF;
    for ($iter = 0; $iter < $max_iter; $iter++) {
        foreach ($particles as $particle) {
            $current_fitness = fitness_function($particle->position);
            if ($current_fitness < $particle->best_fitness) {
                $particle->best_fitness = $current_fitness;
                $particle->best_position = $particle->position;
            }
            if ($current_fitness < $global_best_fitness) {
                $global_best_fitness = $current_fitness;
                $global_best = $particle->position;
            }
        }
        foreach ($particles as $particle) {
            $particle->update_velocity($global_best, $w, $c1, $c2);
            $particle->update_position($lb, $ub);
        }
    }
    return array($global_best, $global_best_fitness);
}

function main() {
    $dim = 30;
    $lb = -100;
    $ub = 100;
    $num_particles = 50;
    $w = 0.7;
    $c1 = 1.5;
    $c2 = 1.5;
    $max_iter = 10000;
    list($best_position, $best_fitness) = optimize($dim, $lb, $ub, $num_particles, $w, $c1, $c2, $max_iter);
    echo 'Best position: ' . implode(', ', $best_position) . "\n";
    echo 'Best fitness: ' . $best_fitness . "\n";
}

main();