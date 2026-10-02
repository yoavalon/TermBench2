<?php

class Particle {
    public $position;
    public $velocity;
    public $best_position;
    public $best_score;

    public function __construct($dimensions) {
        $this->position = array_map(function() { return mt_rand() / mt_getrandmax() * 20 - 10; }, range(1, $dimensions));
        $this->velocity = array_map(function() { return mt_rand() / mt_getrandmax() * 2 - 1; }, range(1, $dimensions));
        $this->best_position = $this->position;
        $this->best_score = INF;
    }
}

class Swarm {
    public $particles;
    public $gbest_position;
    public $gbest_score;

    public function __construct($num_particles, $dimensions) {
        $this->particles = array_fill(0, $num_particles, new Particle($dimensions));
        $this->gbest_position = null;
        $this->gbest_score = INF;
    }

    public function update_gbest() {
        foreach ($this->particles as $particle) {
            if ($particle->best_score < $this->gbest_score) {
                $this->gbest_score = $particle->best_score;
                $this->gbest_position = $particle->best_position;
            }
        }
    }

    public function update_particles($w, $c1, $c2) {
        foreach ($this->particles as $particle) {
            for ($i = 0; $i < count($particle->position); $i++) {
                $r1 = mt_rand() / mt_getrandmax();
                $r2 = mt_rand() / mt_getrandmax();
                $particle->velocity[$i] = $w * $particle->velocity[$i] + $c1 * $r1 * ($particle->best_position[$i] - $particle->position[$i]) + $c2 * $r2 * ($this->gbest_position[$i] - $particle->position[$i]);
                $particle->position[$i] += $particle->velocity[$i];
            }
        }
    }

    public function evaluate($objective_function) {
        foreach ($this->particles as $particle) {
            $score = $objective_function($particle->position);
            if ($score < $particle->best_score) {
                $particle->best_score = $score;
                $particle->best_position = $particle->position;
            }
        }
    }
}

function objective_function($x) {
    return array_sum(array_map(function($xi) { return $xi ** 2; }, $x));
}

function main() {
    $dimensions = 3;
    $num_particles = 20;
    $w = 0.7;
    $c1 = 1.5;
    $c2 = 1.5;
    $iterations = 100;
    $swarm = new Swarm($num_particles, $dimensions);
    for ($i = 0; $i < $iterations; $i++) {
        $swarm->update_gbest();
        $swarm->update_particles($w, $c1, $c2);
        $swarm->evaluate('objective_function');
    }
    echo 'Best score: ' . $swarm->gbest_score . "\n";
    echo 'Best position: ' . implode(', ', $swarm->gbest_position) . "\n";
}

main();