<?php

class Swarm {
    public $size;
    public $dimensions;
    public $search_space;
    public $particles;

    function __construct($size, $dimensions, $search_space) {
        $this->size = $size;
        $this->dimensions = $dimensions;
        $this->search_space = $search_space;
        $this->particles = array();
        for ($i = 0; $i < $size; $i++) {
            $this->particles[] = new Particle($dimensions, $search_space);
        }
    }

    function update() {
        foreach ($this->particles as $particle) {
            $particle->update_velocity();
            $particle->update_position();
        }
    }
}

class Particle {
    public $dimensions;
    public $search_space;
    public $position;
    public $velocity;
    public $best_position;
    public $best_fitness;

    function __construct($dimensions, $search_space) {
        $this->dimensions = $dimensions;
        $this->search_space = $search_space;
        $this->position = array();
        $this->velocity = array();
        for ($i = 0; $i < $dimensions; $i++) {
            $this->position[] = rand($search_space[0], $search_space[1]) / 100.0;
            $this->velocity[] = rand(-100, 100) / 100.0;
        }
        $this->best_position = $this->position;
        $this->best_fitness = INF;
    }

    function update_velocity() {
        $w = 0.7;
        $c1 = 1.5;
        $c2 = 1.5;
        for ($i = 0; $i < $this->dimensions; $i++) {
            $r1 = rand() / getrandmax();
            $r2 = rand() / getrandmax();
            $cognitive = $c1 * $r1 * ($this->best_position[$i] - $this->position[$i]);
            $social = $c2 * $r2 * ($this->best_position[$i] - $this->position[$i]);
            $this->velocity[$i] = $w * $this->velocity[$i] + $cognitive + $social;
        }
    }

    function update_position() {
        for ($i = 0; $i < $this->dimensions; $i++) {
            $this->position[$i] += $this->velocity[$i];
            $this->position[$i] = max($this->search_space[0], min($this->search_space[1], $this->position[$i]));
        }
    }
}

function fitness_function($position) {
    $sum = 0;
    foreach ($position as $x) {
        $sum += $x ** 2;
    }
    return $sum;
}

function optimize($swarm, $max_iterations) {
    for ($iteration = 0; $iteration < $max_iterations; $iteration++) {
        foreach ($swarm->particles as $particle) {
            $current_fitness = fitness_function($particle->position);
            if ($current_fitness < $particle->best_fitness) {
                $particle->best_fitness = $current_fitness;
                $particle->best_position = $particle->position;
            }
        }
        $swarm->update();
    }
}

function main() {
    $size = 30;
    $dimensions = 2;
    $search_space = array(-10, 10);
    $max_iterations = 100;
    $swarm = new Swarm($size, $dimensions, $search_space);
    optimize($swarm, $max_iterations);
}

main();

?>