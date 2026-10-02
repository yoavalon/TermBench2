<?php

class Particle {

    public $position;
    public $velocity;
    public $best_position;
    public $best_score;

    public function __construct($dimensions) {
        $this->position = array_fill(0, $dimensions, rand(-100, 100) / 100);
        $this->velocity = array_fill(0, $dimensions, rand(-100, 100) / 100);
        $this->best_position = $this->position;
        $this->best_score = PHP_FLOAT_MAX;
    }

    public function update_velocity($global_best, $inertia, $cognitive, $social) {
        for ($i = 0; $i < count($this->position); $i++) {
            $r1 = rand() / getrandmax();
            $r2 = rand() / getrandmax();
            $this->velocity[$i] = $inertia * $this->velocity[$i] + $cognitive * $r1 * ($this->best_position[$i] - $this->position[$i]) + $social * $r2 * ($global_best[$i] - $this->position[$i]);
        }
    }

    public function update_position() {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
        }
    }

    public function evaluate($fitness_function) {
        $this->score = $fitness_function($this->position);
        if ($this->score < $this->best_score) {
            $this->best_score = $this->score;
            $this->best_position = $this->position;
        }
    }
}

class Swarm {

    public $particles;
    public $fitness_function;
    public $max_iterations;
    public $inertia;
    public $cognitive;
    public $social;
    public $global_best;
    public $global_best_score;

    public function __construct($size, $dimensions, $fitness_function, $max_iterations, $inertia, $cognitive, $social) {
        $this->particles = array_fill(0, $size, new Particle($dimensions));
        $this->fitness_function = $fitness_function;
        $this->max_iterations = $max_iterations;
        $this->inertia = $inertia;
        $this->cognitive = $cognitive;
        $this->social = $social;
        $this->global_best = null;
        $this->global_best_score = PHP_FLOAT_MAX;
    }

    public function update_global_best() {
        foreach ($this->particles as $particle) {
            if ($particle->best_score < $this->global_best_score) {
                $this->global_best_score = $particle->best_score;
                $this->global_best = $particle->best_position;
            }
        }
    }

    public function optimize() {
        for ($i = 0; $i < $this->max_iterations; $i++) {
            foreach ($this->particles as $particle) {
                $particle->update_velocity($this->global_best, $this->inertia, $this->cognitive, $this->social);
                $particle->update_position();
                $particle->evaluate($this->fitness_function);
            }
            $this->update_global_best();
        }
    }
}

function sphere_function($x) {
    $sum = 0;
    foreach ($x as $xi) {
        $sum += $xi * $xi;
    }
    return $sum;
}

function main() {
    $dimensions = 2;
    $size = 30;
    $max_iterations = 100;
    $inertia = 0.5;
    $cognitive = 1.5;
    $social = 1.5;
    $swarm = new Swarm($size, $dimensions, 'sphere_function', $max_iterations, $inertia, $cognitive, $social);
    $swarm->optimize();
    echo 'Best position: ' . implode(', ', $swarm->global_best) . "\n";
    echo 'Best score: ' . $swarm->global_best_score . "\n";
}

main();

?>