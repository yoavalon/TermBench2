<?php

class Swarm {
    public $size;
    public $dimensions;
    public $search_space;
    public $particles;
    public $best_position;
    public $best_score;

    public function __construct($size, $dimensions, $search_space) {
        $this->size = $size;
        $this->dimensions = $dimensions;
        $this->search_space = $search_space;
        $this->particles = array();
        for ($i = 0; $i < $size; $i++) {
            $this->particles[] = new Particle($dimensions, $search_space);
        }
        $this->best_position = $this->particles[array_rand($this->particles)]->position;
        $this->best_score = INF;
    }

    public function update_best_position() {
        foreach ($this->particles as $particle) {
            if ($particle->score < $this->best_score) {
                $this->best_score = $particle->score;
                $this->best_position = $particle->position;
            }
        }
    }

    public function iterate() {
        foreach ($this->particles as $particle) {
            $particle->update_velocity($this->best_position);
            $particle->move();
            $particle->evaluate();
        }
    }

    public function run($iterations) {
        for ($i = 0; $i < $iterations; $i++) {
            $this->iterate();
            $this->update_best_position();
        }
    }
}

class Particle {
    public $position;
    public $velocity;
    public $best_position;
    public $best_score;

    public function __construct($dimensions, $search_space) {
        $this->position = array();
        $this->velocity = array();
        for ($i = 0; $i < $dimensions; $i++) {
            $this->position[] = mt_rand($search_space[0], $search_space[1]);
            $this->velocity[] = 0.0;
        }
        $this->best_position = $this->position;
        $this->best_score = INF;
    }

    public function update_velocity($global_best) {
        $inertia = 0.5;
        $cognitive_factor = 1.5;
        $social_factor = 1.5;
        for ($i = 0; $i < count($this->position); $i++) {
            $r1 = mt_rand() / mt_getrandmax();
            $r2 = mt_rand() / mt_getrandmax();
            $cognitive = $cognitive_factor * $r1 * ($this->best_position[$i] - $this->position[$i]);
            $social = $social_factor * $r2 * ($global_best[$i] - $this->position[$i]);
            $this->velocity[$i] = $inertia * $this->velocity[$i] + $cognitive + $social;
        }
    }

    public function move() {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
        }
    }

    public function evaluate() {
        $this->score = $this->objective_function();
        if ($this->score < $this->best_score) {
            $this->best_score = $this->score;
            $this->best_position = $this->position;
        }
    }

    public function objective_function() {
        return array_sum(array_map(function($x) { return $x ** 2; }, $this->position));
    }
}

function main() {
    $swarm_size = 30;
    $dimensions = 2;
    $search_space = array(-10, 10);
    $iterations = 100;
    $swarm = new Swarm($swarm_size, $dimensions, $search_space);
    $swarm->run($iterations);
    echo 'Best position: ' . implode(', ', $swarm->best_position) . "\n";
    echo 'Best score: ' . $swarm->best_score . "\n";
}

main();

?>