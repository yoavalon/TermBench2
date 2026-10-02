<?php

class Particle {
    public $position;
    public $velocity;
    public $best_position;
    public $best_score;

    public function __construct($dimensions) {
        $this->position = array_map(function() { return mt_rand(-1000, 1000) / 100; }, range(0, $dimensions - 1));
        $this->velocity = array_map(function() { return mt_rand(-100, 100) / 100; }, range(0, $dimensions - 1));
        $this->best_position = $this->position;
        $this->best_score = INF;
    }

    public function update_velocity($global_best_position, $w, $c1, $c2) {
        for ($i = 0; $i < count($this->velocity); $i++) {
            $r1 = mt_rand() / mt_getrandmax();
            $r2 = mt_rand() / mt_getrandmax();
            $cognitive = $c1 * $r1 * ($this->best_position[$i] - $this->position[$i]);
            $social = $c2 * $r2 * ($global_best_position[$i] - $this->position[$i]);
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

    public function evaluate($objective_function) {
        $score = $objective_function($this->position);
        if ($score < $this->best_score) {
            $this->best_score = $score;
            $this->best_position = $this->position;
        }
    }
}

class Swarm {
    public $particles;
    public $global_best_position;
    public $global_best_score;

    public function __construct($num_particles, $dimensions) {
        $this->particles = array_map(function() use ($dimensions) { return new Particle($dimensions); }, range(0, $num_particles - 1));
        $this->global_best_position = array_map(function() { return mt_rand(-1000, 1000) / 100; }, range(0, $dimensions - 1));
        $this->global_best_score = INF;
    }

    public function update_global_best() {
        foreach ($this->particles as $particle) {
            if ($particle->best_score < $this->global_best_score) {
                $this->global_best_score = $particle->best_score;
                $this->global_best_position = $particle->best_position;
            }
        }
    }

    public function optimize($objective_function, $w, $c1, $c2, $iterations) {
        for ($i = 0; $i < $iterations; $i++) {
            foreach ($this->particles as $particle) {
                $particle->update_velocity($this->global_best_position, $w, $c1, $c2);
                $particle->update_position();
                $particle->evaluate($objective_function);
            }
            $this->update_global_best();
        }
    }
}

function objective_function($x) {
    return array_sum(array_map(function($xi) { return $xi ** 2; }, $x));
}

function main() {
    $dimensions = 3;
    $num_particles = 10;
    $w = 0.7;
    $c1 = 1.5;
    $c2 = 1.5;
    $iterations = 50;
    $swarm = new Swarm($num_particles, $dimensions);
    $swarm->optimize('objective_function', $w, $c1, $c2, $iterations);
    echo 'Best position: ' . implode(', ', $swarm->global_best_position) . "\n";
    echo 'Best score: ' . $swarm->global_best_score . "\n";
}

main();