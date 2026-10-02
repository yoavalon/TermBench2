<?php

class Particle {
    public $position;
    public $velocity;
    public $best_position;
    public $best_score;

    public function __construct($dimensions) {
        $this->position = array_map(function() { return mt_rand() / mt_getrandmax() * 20 - 10; }, range(0, $dimensions - 1));
        $this->velocity = array_map(function() { return mt_rand() / mt_getrandmax() * 2 - 1; }, range(0, $dimensions - 1));
        $this->best_position = $this->position;
        $this->best_score = INF;
    }

    public function update_velocity($global_best, $w, $c1, $c2) {
        for ($i = 0; $i < count($this->position); $i++) {
            $r1 = mt_rand() / mt_getrandmax();
            $r2 = mt_rand() / mt_getrandmax();
            $cognitive = $c1 * $r1 * ($this->best_position[$i] - $this->position[$i]);
            $social = $c2 * $r2 * ($global_best[$i] - $this->position[$i]);
            $this->velocity[$i] = $w * $this->velocity[$i] + $cognitive + $social;
        }
    }

    public function update_position() {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
            if ($this->position[$i] < -10) {
                $this->position[$i] = -10;
            } elseif ($this->position[$i] > 10) {
                $this->position[$i] = 10;
            }
        }
    }
}

class Swarm {
    public $particles;
    public $global_best;
    public $global_best_score;

    public function __construct($num_particles, $dimensions) {
        $this->particles = array_fill(0, $num_particles, new Particle($dimensions));
        $this->global_best = array_fill(0, $dimensions, INF);
        $this->global_best_score = INF;
    }

    public function update_global_best() {
        foreach ($this->particles as $particle) {
            if ($particle->best_score < $this->global_best_score) {
                $this->global_best = $particle->best_position;
                $this->global_best_score = $particle->best_score;
            }
        }
    }

    public function optimize($iterations, $w, $c1, $c2) {
        for ($i = 0; $i < $iterations; $i++) {
            $this->update_global_best();
            foreach ($this->particles as $particle) {
                $particle->update_velocity($this->global_best, $w, $c1, $c2);
                $particle->update_position();
            }
        }
    }
}

function objective_function($x) {
    return array_sum(array_map(function($xi) { return $xi ** 2; }, $x));
}

function main() {
    $dimensions = 30;
    $num_particles = 30;
    $iterations = 100;
    $w = 0.7;
    $c1 = 2.0;
    $c2 = 2.0;
    $swarm = new Swarm($num_particles, $dimensions);
    foreach ($swarm->particles as $particle) {
        $score = objective_function($particle->position);
        if ($score < $particle->best_score) {
            $particle->best_score = $score;
        }
    }
    $swarm->optimize($iterations, $w, $c1, $c2);
    $best_score = $swarm->global_best_score;
    echo 'Best Score: ' . $best_score . "\n";
}

main();