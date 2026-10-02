<?php

class Particle {

    public $position;
    public $velocity;
    public $best_position;
    public $best_score;

    public function __construct($dimensions, $lower_bound, $upper_bound) {
        $this->position = array_fill(0, $dimensions, mt_rand($lower_bound * 1000, $upper_bound * 1000) / 1000);
        $this->velocity = array_fill(0, $dimensions, mt_rand(-1000, 1000) / 1000);
        $this->best_position = $this->position;
        $this->best_score = INF;
    }

    public function update_velocity($global_best_position, $w, $c1, $c2) {
        for ($i = 0; $i < count($this->position); $i++) {
            $r1 = mt_rand() / mt_getrandmax();
            $r2 = mt_rand() / mt_getrandmax();
            $this->velocity[$i] = $w * $this->velocity[$i] + $c1 * $r1 * ($this->best_position[$i] - $this->position[$i]) + $c2 * $r2 * ($global_best_position[$i] - $this->position[$i]);
        }
    }

    public function update_position() {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
        }
    }

    public function evaluate($fitness_function) {
        $score = $fitness_function($this->position);
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

    public function __construct($size, $dimensions, $lower_bound, $upper_bound) {
        $this->particles = array_fill(0, $size, null);
        for ($i = 0; $i < $size; $i++) {
            $this->particles[$i] = new Particle($dimensions, $lower_bound, $upper_bound);
        }
        $this->global_best_position = array_fill(0, $dimensions, mt_rand($lower_bound * 1000, $upper_bound * 1000) / 1000);
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

    public function iterate($fitness_function, $w, $c1, $c2) {
        foreach ($this->particles as $particle) {
            $particle->update_velocity($this->global_best_position, $w, $c1, $c2);
            $particle->update_position();
            $particle->evaluate($fitness_function);
        }
        $this->update_global_best();
    }
}

function fitness_function($position) {
    $sum = 0;
    foreach ($position as $x) {
        $sum += pow($x, 2);
    }
    return $sum;
}

function main() {
    $dimensions = 2;
    $lower_bound = -10;
    $upper_bound = 10;
    $swarm_size = 30;
    $w = 0.7;
    $c1 = 1.5;
    $c2 = 1.5;
    $iterations = 100;
    $swarm = new Swarm($swarm_size, $dimensions, $lower_bound, $upper_bound);
    for ($i = 0; $i < $iterations; $i++) {
        $swarm->iterate('fitness_function', $w, $c1, $c2);
    }
    echo 'Global best score: ' . $swarm->global_best_score . "\n";
    echo 'Global best position: ' . implode(', ', $swarm->global_best_position) . "\n";
}

main();

?>