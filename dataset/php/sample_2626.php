<?php

class Particle {
    public $position;
    public $velocity;
    public $best_position;
    public $best_score;

    function __construct($dimensions, $position = null) {
        $this->position = $position !== null ? $position : array_map(function() { return mt_rand() / mt_getrandmax() * 2 - 1; }, range(0, $dimensions - 1));
        $this->velocity = array_map(function() { return mt_rand() / mt_getrandmax() * 2 - 1; }, range(0, $dimensions - 1));
        $this->best_position = $this->position;
        $this->best_score = INF;
    }

    function update_velocity($global_best, $w = 0.7, $c1 = 1.5, $c2 = 1.5) {
        for ($i = 0; $i < count($this->position); $i++) {
            $r1 = mt_rand() / mt_getrandmax();
            $r2 = mt_rand() / mt_getrandmax();
            $cognitive = $c1 * $r1 * ($this->best_position[$i] - $this->position[$i]);
            $social = $c2 * $r2 * ($global_best[$i] - $this->position[$i]);
            $this->velocity[$i] = $w * $this->velocity[$i] + $cognitive + $social;
        }
    }

    function update_position($bounds) {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
            if ($bounds) {
                $this->position[$i] = max($bounds[0], min($bounds[1], $this->position[$i]));
            }
        }
    }

    function evaluate($function) {
        $this->current_score = $function($this->position);
        if ($this->current_score < $this->best_score) {
            $this->best_score = $this->current_score;
            $this->best_position = $this->position;
        }
    }
}

class Swarm {
    public $particles;
    public $global_best;
    public $global_best_score;
    public $bounds;

    function __construct($dimensions, $num_particles, $bounds = null) {
        $this->particles = array_map(function() use ($dimensions) { return new Particle($dimensions); }, range(0, $num_particles - 1));
        $this->global_best = null;
        $this->global_best_score = INF;
        $this->bounds = $bounds;
    }

    function update_global_best() {
        foreach ($this->particles as $particle) {
            if ($particle->best_score < $this->global_best_score) {
                $this->global_best_score = $particle->best_score;
                $this->global_best = $particle->best_position;
            }
        }
    }

    function optimize($function, $iterations) {
        for ($i = 0; $i < $iterations; $i++) {
            $this->update_global_best();
            foreach ($this->particles as $particle) {
                $particle->update_velocity($this->global_best);
                $particle->update_position($this->bounds);
                $particle->evaluate($function);
            }
        }
    }
}

function objective_function($x) {
    return array_sum(array_map(function($xi) { return $xi ** 2; }, $x));
}

function main() {
    $dimensions = 2;
    $num_particles = 30;
    $bounds = [-10, 10];
    $iterations = 100;
    $swarm = new Swarm($dimensions, $num_particles, $bounds);
    $swarm->optimize('objective_function', $iterations);
    echo 'Global Best Position: ' . implode(', ', $swarm->global_best) . "\n";
    echo 'Global Best Score: ' . $swarm->global_best_score . "\n";
}

main();

?>