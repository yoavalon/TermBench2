<?php

class Particle {
    public $position;
    public $velocity;
    public $best_position;
    public $best_score;

    public function __construct($dimensions, $bounds) {
        $this->position = array_map(function() use ($bounds) {
            return $bounds[0] + ($bounds[1] - $bounds[0]) * rand() / mt_getrandmax();
        }, range(0, $dimensions - 1));
        $this->velocity = array_fill(0, $dimensions, 0.0);
        $this->best_position = $this->position;
        $this->best_score = INF;
    }
}

class Swarm {
    public $particles;
    public $bounds;
    public $function;
    public $w;
    public $c1;
    public $c2;
    public $best_swarm_position;
    public $best_swarm_score;

    public function __construct($particles, $bounds, $function, $w, $c1, $c2) {
        $this->particles = $particles;
        $this->bounds = $bounds;
        $this->function = $function;
        $this->w = $w;
        $this->c1 = $c1;
        $this->c2 = $c2;
        $this->best_swarm_position = array_fill(0, count($bounds), 0.0);
        $this->best_swarm_score = INF;
    }

    public function evaluate() {
        foreach ($this->particles as $particle) {
            $score = call_user_func($this->function, $particle->position);
            if ($score < $particle->best_score) {
                $particle->best_score = $score;
                $particle->best_position = $particle->position;
            }
            if ($score < $this->best_swarm_score) {
                $this->best_swarm_score = $score;
                $this->best_swarm_position = $particle->position;
            }
        }
    }

    public function update() {
        foreach ($this->particles as $particle) {
            for ($i = 0; $i < count($particle->position); $i++) {
                $r1 = rand() / mt_getrandmax();
                $r2 = rand() / mt_getrandmax();
                $velocity_cognitive = $this->c1 * $r1 * ($particle->best_position[$i] - $particle->position[$i]);
                $velocity_social = $this->c2 * $r2 * ($this->best_swarm_position[$i] - $particle->position[$i]);
                $particle->velocity[$i] = $this->w * $particle->velocity[$i] + $velocity_cognitive + $velocity_social;
                $particle->position[$i] += $particle->velocity[$i];
                $particle->position[$i] = max($this->bounds[0], min($this->bounds[1], $particle->position[$i]));
            }
        }
    }
}

function objective_function($x) {
    return array_sum(array_map(function($xi) {
        return $xi ** 2;
    }, $x));
}

function optimize($dimensions, $bounds, $num_particles, $max_iterations, $w, $c1, $c2) {
    $particles = array_map(function() use ($dimensions, $bounds) {
        return new Particle($dimensions, $bounds);
    }, range(0, $num_particles - 1));
    $swarm = new Swarm($particles, $bounds, 'objective_function', $w, $c1, $c2);
    for ($i = 0; $i < $max_iterations; $i++) {
        $swarm->evaluate();
        $swarm->update();
    }
    return array($swarm->best_swarm_position, $swarm->best_swarm_score);
}

if (__FILE__ == $_SERVER['argv'][0]) {
    $dimensions = 2;
    $bounds = array(-10, 10);
    $num_particles = 30;
    $max_iterations = 100;
    $w = 0.729;
    $c1 = 1.494;
    $c2 = 1.494;
    $result = optimize($dimensions, $bounds, $num_particles, $max_iterations, $w, $c1, $c2);
    echo 'Best position: ' . implode(', ', $result[0]) . PHP_EOL;
    echo 'Best score: ' . $result[1] . PHP_EOL;
}

?>