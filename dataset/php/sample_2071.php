<?php

class Particle {

    public $position;
    public $velocity;
    public $best_pos;
    public $best_score;

    function __construct($dim, $bounds) {
        $this->position = array_map(function($b) { return mt_rand($b[0], $b[1]) / 1000.0; }, $bounds);
        $this->velocity = array_fill(0, $dim, mt_rand(-1000, 1000) / 1000.0);
        $this->best_pos = $this->position;
        $this->best_score = PHP_FLOAT_MAX;
    }

    function update_velocity($global_best, $w = 0.7, $c1 = 1.5, $c2 = 1.5) {
        for ($i = 0; $i < count($this->position); $i++) {
            $r1 = mt_rand() / mt_getrandmax();
            $r2 = mt_rand() / mt_getrandmax();
            $cognitive = $c1 * $r1 * ($this->best_pos[$i] - $this->position[$i]);
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
}

class Swarm {

    public $particles;
    public $global_best;
    public $global_best_score;

    function __construct($dim, $num_particles, $bounds) {
        $this->particles = array_fill(0, $num_particles, new Particle($dim, $bounds));
        $this->global_best = array_fill(0, $dim, PHP_FLOAT_MAX);
        $this->global_best_score = PHP_FLOAT_MAX;
    }

    function update_global_best() {
        foreach ($this->particles as $particle) {
            $score = $this->evaluate($particle->position);
            if ($score < $this->global_best_score) {
                $this->global_best = $particle->position;
                $this->global_best_score = $score;
                $particle->best_score = $score;
                $particle->best_pos = $particle->position;
            }
        }
    }

    function evaluate($position) {
        return array_sum(array_map(function($x) { return $x * $x; }, $position));
    }

    function run($iterations) {
        for ($i = 0; $i < $iterations; $i++) {
            foreach ($this->particles as $particle) {
                $particle->update_velocity($this->global_best);
                $particle->update_position($this->bound);
            }
            $this->update_global_best();
        }
    }
}

function main() {
    $dim = 3;
    $num_particles = 20;
    $bounds = array_fill(0, $dim, array(-10, 10));
    $swarm = new Swarm($dim, $num_particles, $bounds);
    $swarm->run(100);
    echo 'Global Best Position: ' . implode(', ', $swarm->global_best) . "\n";
    echo 'Global Best Score: ' . $swarm->global_best_score . "\n";
}

main();

?>