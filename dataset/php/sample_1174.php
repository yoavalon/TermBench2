<?php

class Particle {

    public $position;
    public $velocity;
    public $best_position;
    public $best_score;

    function __construct($dimensions) {
        $this->position = array_fill(0, $dimensions, 0.0);
        $this->velocity = array_fill(0, $dimensions, 0.0);
        $this->best_position = array_fill(0, $dimensions, 0.0);
        $this->best_score = PHP_FLOAT_MAX;
    }

    function update_velocity($global_best, $w, $c1, $c2) {
        for ($i = 0; $i < count($this->position); $i++) {
            $r1 = 0.5;
            $r2 = 0.5;
            $cognitive = $c1 * $r1 * ($this->best_position[$i] - $this->position[$i]);
            $social = $c2 * $r2 * ($global_best[$i] - $this->position[$i]);
            $this->velocity[$i] = $w * $this->velocity[$i] + $cognitive + $social;
        }
    }

    function update_position($bounds) {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
            $this->position[$i] = max($bounds[$i][0], min($this->position[$i], $bounds[$i][1]));
        }
    }

    function evaluate($score_function) {
        $this->best_score = $score_function($this->position);
        if ($this->best_score < $score_function($this->best_position)) {
            $this->best_position = $this->position;
        }
    }
}

class Swarm {

    public $particles;
    public $global_best;
    public $global_best_score;
    public $bounds;
    public $w;
    public $c1;
    public $c2;

    function __construct($dimensions, $num_particles, $bounds, $w, $c1, $c2) {
        $this->particles = array_fill(0, $num_particles, new Particle($dimensions));
        $this->global_best = array_fill(0, $dimensions, 0.0);
        $this->global_best_score = PHP_FLOAT_MAX;
        $this->bounds = $bounds;
        $this->w = $w;
        $this->c1 = $c1;
        $this->c2 = $c2;
    }

    function update_global_best() {
        foreach ($this->particles as $particle) {
            if ($particle->best_score < $this->global_best_score) {
                $this->global_best_score = $particle->best_score;
                $this->global_best = $particle->best_position;
            }
        }
    }

    function iterate($score_function) {
        foreach ($this->particles as $particle) {
            $particle->update_velocity($this->global_best, $this->w, $this->c1, $this->c2);
            $particle->update_position($this->bounds);
            $particle->evaluate($score_function);
        }
        $this->update_global_best();
    }
}

function main() {
    $dimensions = 2;
    $num_particles = 10;
    $bounds = array(array(-10, 10), array(-10, 10));
    $w = 0.7;
    $c1 = 2.0;
    $c2 = 2.0;

    $score_function = function($position) {
        return array_sum(array_map(function($x) { return $x ** 2; }, $position));
    };

    $swarm = new Swarm($dimensions, $num_particles, $bounds, $w, $c1, $c2);
    while (true) {
        $swarm->iterate($score_function);
    }
}

main();

?>