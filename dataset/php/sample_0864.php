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
        for ($i = 0; $i < count($this->position); $i++) {
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
        }
    }

    public function evaluate($fitness_function) {
        $this->best_score = $fitness_function($this->position);
        return $this->best_score;
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
}

function fitness_function($x) {
    return array_sum(array_map(function($xi) { return $xi ** 2; }, $x));
}

function optimize($swarm, $w, $c1, $c2, $iterations) {
    for ($i = 0; $i < $iterations; $i++) {
        foreach ($swarm->particles as $particle) {
            $particle->update_velocity($swarm->global_best_position, $w, $c1, $c2);
            $particle->update_position();
            $particle->evaluate('fitness_function');
        }
        $swarm->update_global_best();
    }
    return array($swarm->global_best_position, $swarm->global_best_score);
}

function main() {
    $dimensions = 10;
    $num_particles = 20;
    $w = 0.7;
    $c1 = 2.0;
    $c2 = 2.0;
    $iterations = 100;
    $swarm = new Swarm($num_particles, $dimensions);
    list($best_position, $best_score) = optimize($swarm, $w, $c1, $c2, $iterations);
    echo 'Best position: ' . implode(', ', $best_position) . PHP_EOL;
    echo 'Best score: ' . $best_score . PHP_EOL;
}

main();

?>