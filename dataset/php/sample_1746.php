<?php

class Particle {
    public $position;
    public $velocity;
    public $best_position;
    public $best_score;

    public function __construct($dimensions) {
        $this->position = array_map(function() { return rand(-1000, 1000) / 100; }, array_fill(0, $dimensions, 0));
        $this->velocity = array_map(function() { return rand(-100, 100) / 100; }, array_fill(0, $dimensions, 0));
        $this->best_position = $this->position;
        $this->best_score = INF;
    }

    public function update_velocity($global_best_position, $w = 0.7, $c1 = 1.5, $c2 = 1.5) {
        for ($i = 0; $i < count($this->velocity); $i++) {
            $r1 = rand() / getrandmax();
            $r2 = rand() / getrandmax();
            $cognitive = $c1 * $r1 * ($this->best_position[$i] - $this->position[$i]);
            $social = $c2 * $r2 * ($global_best_position[$i] - $this->position[$i]);
            $this->velocity[$i] = $w * $this->velocity[$i] + $cognitive + $social;
        }
    }

    public function update_position() {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
        }
    }

    public function evaluate($cost_function) {
        $score = $cost_function($this->position);
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

    public function __construct($size, $dimensions) {
        $this->particles = array_map(function() use ($dimensions) { return new Particle($dimensions); }, array_fill(0, $size, 0));
        $this->global_best_position = null;
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

    public function update_swarm() {
        foreach ($this->particles as $particle) {
            $particle->update_velocity($this->global_best_position);
            $particle->update_position();
        }
    }
}

function cost_function($position) {
    return array_sum(array_map(function($x) { return $x ** 2; }, $position));
}

function main() {
    $dimensions = 10;
    $swarm_size = 20;
    $swarm = new Swarm($swarm_size, $dimensions);
    while (true) {
        foreach ($swarm->particles as $particle) {
            $particle->evaluate('cost_function');
        }
        $swarm->update_global_best();
        $swarm->update_swarm();
    }
}

main();

?>