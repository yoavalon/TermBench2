<?php

class Particle {
    public $position;
    public $velocity;
    public $best_position;
    public $best_score;

    function __construct($dimensions) {
        $this->position = array_fill(0, $dimensions, mt_rand(-1000, 1000) / 100);
        $this->velocity = array_fill(0, $dimensions, mt_rand(-100, 100) / 100);
        $this->best_position = $this->position;
        $this->best_score = INF;
    }
}

class Swarm {
    public $particles;
    public $global_best_position;
    public $global_best_score;

    function __construct($num_particles, $dimensions) {
        $this->particles = array_fill(0, $num_particles, new Particle($dimensions));
        $this->global_best_position = array_fill(0, $dimensions, 0.0);
        $this->global_best_score = INF;
    }

    function update_global_best() {
        foreach ($this->particles as $particle) {
            $score = $this->evaluate($particle->position);
            if ($score < $this->global_best_score) {
                $this->global_best_score = $score;
                $this->global_best_position = $particle->position;
            }
        }
    }

    function evaluate($position) {
        $sum = 0;
        foreach ($position as $x) {
            $sum += $x * $x;
        }
        return $sum;
    }

    function update_particles($w, $c1, $c2) {
        foreach ($this->particles as $particle) {
            for ($i = 0; $i < count($particle->position); $i++) {
                $r1 = mt_rand() / mt_getrandmax();
                $r2 = mt_rand() / mt_getrandmax();
                $particle->velocity[$i] = $w * $particle->velocity[$i] + $c1 * $r1 * ($particle->best_position[$i] - $particle->position[$i]) + $c2 * $r2 * ($this->global_best_position[$i] - $particle->position[$i]);
                $particle->position[$i] += $particle->velocity[$i];
                $particle->best_score = min($particle->best_score, $this->evaluate($particle->position));
                if ($particle->best_score < $this->evaluate($particle->best_position)) {
                    $particle->best_position = $particle->position;
                }
            }
        }
    }
}

function main() {
    $dimensions = 30;
    $num_particles = 30;
    $w = 0.7;
    $c1 = 1.5;
    $c2 = 1.5;
    $iterations = 100;
    $swarm = new Swarm($num_particles, $dimensions);
    for ($i = 0; $i < $iterations; $i++) {
        $swarm->update_global_best();
        $swarm->update_particles($w, $c1, $c2);
    }
    echo 'Best score: ' . $swarm->global_best_score;
}

main();

?>