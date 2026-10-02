<?php

class Particle {
    public $position;
    public $velocity;
    public $best_pos;
    public $best_score;

    function __construct($dim) {
        $this->position = array_fill(0, $dim, 0.0);
        $this->velocity = array_fill(0, $dim, 0.0);
        $this->best_pos = array_fill(0, $dim, 0.0);
        $this->best_score = INF;
    }

    function update_velocity($global_best, $w, $c1, $c2) {
        for ($i = 0; $i < count($this->position); $i++) {
            $r1 = rand() / getrandmax();
            $r2 = rand() / getrandmax();
            $this->velocity[$i] = $w * $this->velocity[$i] + $c1 * $r1 * ($this->best_pos[$i] - $this->position[$i]) + $c2 * $r2 * ($global_best[$i] - $this->position[$i]);
        }
    }

    function update_position($bounds) {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
            $this->position[$i] = max($bounds[0][$i], min($bounds[1][$i], $this->position[$i]));
        }
    }
}

class Swarm {
    public $particles;
    public $best_global_pos;
    public $best_global_score;

    function __construct($num_particles, $dim, $bounds) {
        $this->particles = array_fill(0, $num_particles, new Particle($dim));
        $this->best_global_pos = array_fill(0, $dim, 0.0);
        $this->best_global_score = INF;
    }

    function update_global_best() {
        foreach ($this->particles as $particle) {
            if ($particle->best_score < $this->best_global_score) {
                $this->best_global_score = $particle->best_score;
                $this->best_global_pos = $particle->best_pos;
            }
        }
    }

    function optimize($fitness_func, $max_iter, $w, $c1, $c2) {
        for ($t = 0; $t < $max_iter; $t++) {
            foreach ($this->particles as $particle) {
                $particle->update_velocity($this->best_global_pos, $w, $c1, $c2);
                $particle->update_position($bounds);
                $score = $fitness_func($particle->position);
                if ($score < $particle->best_score) {
                    $particle->best_score = $score;
                    $particle->best_pos = $particle->position;
                }
            }
            $this->update_global_best();
        }
    }
}

function fitness_function($position) {
    return array_sum(array_map(function($x) { return $x ** 2; }, $position));
}

function main() {
    $num_particles = 30;
    $dim = 2;
    $bounds = array(array_fill(0, $dim, 0.0), array_fill(0, $dim, 10.0));
    $max_iter = 100;
    $w = 0.7;
    $c1 = 2.0;
    $c2 = 2.0;
    $swarm = new Swarm($num_particles, $dim, $bounds);
    $swarm->optimize('fitness_function', $max_iter, $w, $c1, $c2);
    print_r($swarm->best_global_pos);
    echo " " . $swarm->best_global_score . "\n";
}

main();

?>