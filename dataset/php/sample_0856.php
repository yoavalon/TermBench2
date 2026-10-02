<?php

class Particle {
    public $position;
    public $velocity;
    public $best_position;
    public $best_score;

    public function __construct($dimensions, $bounds) {
        $this->position = array_map(function($b) { return mt_rand($b[0] * 1000, $b[1] * 1000) / 1000; }, $bounds);
        $this->velocity = array_map(function() { return mt_rand(-1000, 1000) / 1000; }, array_fill(0, $dimensions, 0));
        $this->best_position = array_slice($this->position, 0);
        $this->best_score = INF;
    }

    public function update_velocity($global_best, $w, $c1, $c2) {
        for ($i = 0; $i < count($this->velocity); $i++) {
            $r1 = mt_rand() / mt_getrandmax();
            $r2 = mt_rand() / mt_getrandmax();
            $cognitive = $c1 * $r1 * ($this->best_position[$i] - $this->position[$i]);
            $social = $c2 * $r2 * ($global_best[$i] - $this->position[$i]);
            $this->velocity[$i] = $w * $this->velocity[$i] + $cognitive + $social;
        }
    }

    public function update_position($bounds) {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
            $this->position[$i] = max($bounds[$i][0], min($bounds[$i][1], $this->position[$i]));
        }
    }
}

class Swarm {
    public $particles;
    public $best_position;
    public $best_score;
    public $function;

    public function __construct($num_particles, $dimensions, $bounds, $function) {
        $this->particles = array_fill(0, $num_particles, new Particle($dimensions, $bounds));
        $this->best_position = null;
        $this->best_score = INF;
        $this->function = $function;
    }

    public function optimize($max_iterations, $w, $c1, $c2) {
        for ($iteration = 0; $iteration < $max_iterations; $iteration++) {
            foreach ($this->particles as $particle) {
                $score = $this->function($particle->position);
                if ($score < $particle->best_score) {
                    $particle->best_score = $score;
                    $particle->best_position = array_slice($particle->position, 0);
                }
                if ($score < $this->best_score) {
                    $this->best_score = $score;
                    $this->best_position = array_slice($particle->position, 0);
                }
            }
            foreach ($this->particles as $particle) {
                $particle->update_velocity($this->best_position, $w, $c1, $c2);
                $particle->update_position($bounds);
            }
        }
    }
}

function objective_function($x) {
    return array_sum(array_map(function($xi) { return pow($xi - 2, 2); }, $x));
}

function main() {
    $dimensions = 3;
    $bounds = array_fill(0, $dimensions, [-10, 10]);
    $num_particles = 20;
    $max_iterations = 100;
    $w = 0.7;
    $c1 = 1.5;
    $c2 = 1.5;
    $swarm = new Swarm($num_particles, $dimensions, $bounds, 'objective_function');
    $swarm->optimize($max_iterations, $w, $c1, $c2);
    print_r($swarm->best_position);
    echo $swarm->best_score;
}

main();

?>