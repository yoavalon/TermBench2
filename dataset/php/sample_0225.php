<?php

class PSOSettings {
    public $dimensions;
    public $population_size;
    public $max_iterations;
    public $c1 = 2.0;
    public $c2 = 2.0;
    public $w = 0.7;

    public function __construct($dimensions, $population_size, $max_iterations) {
        $this->dimensions = $dimensions;
        $this->population_size = $population_size;
        $this->max_iterations = $max_iterations;
    }
}

class Particle {
    public $position;
    public $velocity;
    public $best_position;
    public $best_fitness;

    public function __construct($dimensions, $lower_bound, $upper_bound) {
        $this->position = array_map(function() use ($lower_bound, $upper_bound) {
            return mt_rand() / mt_getrandmax() * ($upper_bound - $lower_bound) + $lower_bound;
        }, array_fill(0, $dimensions, 0));
        $this->velocity = array_map(function() {
            return mt_rand() / mt_getrandmax() * 2 - 1;
        }, array_fill(0, $dimensions, 0));
        $this->best_position = $this->position;
        $this->best_fitness = INF;
    }
}

function fitness($position) {
    return array_sum(array_map(function($x) {
        return $x ** 2;
    }, $position));
}

function update_velocity($particle, $global_best, $settings) {
    for ($i = 0; $i < $settings->dimensions; $i++) {
        $r1 = mt_rand() / mt_getrandmax();
        $r2 = mt_rand() / mt_getrandmax();
        $cognitive = $settings->c1 * $r1 * ($particle->best_position[$i] - $particle->position[$i]);
        $social = $settings->c2 * $r2 * ($global_best[$i] - $particle->position[$i]);
        $particle->velocity[$i] = $settings->w * $particle->velocity[$i] + $cognitive + $social;
    }
}

function update_position($particle, $settings) {
    for ($i = 0; $i < $settings->dimensions; $i++) {
        $particle->position[$i] += $particle->velocity[$i];
        if ($particle->position[$i] < -10) {
            $particle->position[$i] = -10;
        } elseif ($particle->position[$i] > 10) {
            $particle->position[$i] = 10;
        }
    }
}

function optimize($settings) {
    $population = array_fill(0, $settings->population_size, new Particle($settings->dimensions, -10, 10));
    $global_best = array_fill(0, $settings->dimensions, 0);
    $global_best_fitness = INF;
    for ($iteration = 0; $iteration < $settings->max_iterations; $iteration++) {
        foreach ($population as $particle) {
            $current_fitness = fitness($particle->position);
            if ($current_fitness < $particle->best_fitness) {
                $particle->best_fitness = $current_fitness;
                $particle->best_position = $particle->position;
            }
            if ($current_fitness < $global_best_fitness) {
                $global_best_fitness = $current_fitness;
                $global_best = $particle->position;
            }
        }
        foreach ($population as $particle) {
            update_velocity($particle, $global_best, $settings);
            update_position($particle, $settings);
        }
    }
    return array($global_best, $global_best_fitness);
}

function main() {
    $settings = new PSOSettings(2, 30, 100);
    list($best_position, $best_fitness) = optimize($settings);
    echo 'Best position: ' . implode(', ', $best_position) . "\n";
    echo 'Best fitness: ' . $best_fitness . "\n";
}

main();
?>