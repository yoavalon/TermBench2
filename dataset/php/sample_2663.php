<?php

class Swarm {
    public $size;
    public $dimensions;
    public $particles;
    public $global_best;

    public function __construct($size, $dimensions) {
        $this->size = $size;
        $this->dimensions = $dimensions;
        $this->particles = array();
        for ($i = 0; $i < $size; $i++) {
            $this->particles[] = new Particle($dimensions);
        }
        $this->global_best = null;
    }

    public function update_global_best() {
        foreach ($this->particles as $particle) {
            if ($this->global_best === null || $particle->best_score < $this->global_best->best_score) {
                $this->global_best = $particle;
            }
        }
    }

    public function update_particles() {
        foreach ($this->particles as $particle) {
            $particle->update_velocity($this->global_best);
            $particle->update_position();
        }
    }
}

class Particle {
    public $position;
    public $velocity;
    public $best_position;
    public $best_score;

    public function __construct($dimensions) {
        $this->position = array();
        $this->velocity = array();
        for ($i = 0; $i < $dimensions; $i++) {
            $this->position[] = rand(-1000, 1000) / 100;
            $this->velocity[] = rand(-100, 100) / 100;
        }
        $this->best_position = $this->position;
        $this->best_score = PHP_FLOAT_MAX;
    }

    public function update_velocity($global_best) {
        $w = 0.729;
        $c1 = 1.494;
        $c2 = 1.494;
        for ($i = 0; $i < count($this->velocity); $i++) {
            $r1 = rand() / getrandmax();
            $r2 = rand() / getrandmax();
            $cognitive = $c1 * $r1 * ($this->best_position[$i] - $this->position[$i]);
            $social = $c2 * $r2 * ($global_best->best_position[$i] - $this->position[$i]);
            $this->velocity[$i] = $w * $this->velocity[$i] + $cognitive + $social;
        }
    }

    public function update_position() {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
            $this->position[$i] = max(-10, min(10, $this->position[$i]));
        }
    }

    public function evaluate($objective_function) {
        $this->best_score = $objective_function($this->position);
        if ($this->best_score < $this->best_score) {
            $this->best_position = $this->position;
        }
    }
}

function objective_function($x) {
    $sum = 0;
    foreach ($x as $xi) {
        $sum += $xi ** 2;
    }
    return $sum;
}

function main() {
    $swarm_size = 30;
    $dimensions = 2;
    $swarm = new Swarm($swarm_size, $dimensions);
    for ($i = 0; $i < 100; $i++) {
        $swarm->update_global_best();
        foreach ($swarm->particles as $particle) {
            $particle->evaluate('objective_function');
        }
        $swarm->update_particles();
    }
    echo $swarm->global_best->best_score . ' ' . implode(' ', $swarm->global_best->best_position) . "\n";
}

main();

?>