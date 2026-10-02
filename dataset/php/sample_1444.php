<?php

class Particle {
    public $position;
    public $velocity;
    public $best_position;
    public $best_score;

    public function __construct($dimensions, $bounds) {
        $this->position = array_map(function() use ($bounds) {
            return rand($bounds[0] * 1000000, $bounds[1] * 1000000) / 1000000;
        }, array_fill(0, $dimensions, 0));
        $this->velocity = array_map(function() {
            return rand(-1000000, 1000000) / 1000000;
        }, array_fill(0, $dimensions, 0));
        $this->best_position = $this->position;
        $this->best_score = INF;
    }

    public function update_velocity($global_best, $w = 0.7, $c1 = 1.5, $c2 = 1.5) {
        for ($i = 0; $i < count($this->velocity); $i++) {
            $r1 = rand() / getrandmax();
            $r2 = rand() / getrandmax();
            $this->velocity[$i] = $w * $this->velocity[$i] + $c1 * $r1 * ($this->best_position[$i] - $this->position[$i]) + $c2 * $r2 * ($global_best[$i] - $this->position[$i]);
        }
    }

    public function update_position($bounds) {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
            $this->position[$i] = max($bounds[0], min($bounds[1], $this->position[$i]));
        }
    }

    public function evaluate($objective_function) {
        $score = $objective_function($this->position);
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

    public function __construct($num_particles, $dimensions, $bounds) {
        $this->particles = array_map(function() use ($dimensions, $bounds) {
            return new Particle($dimensions, $bounds);
        }, array_fill(0, $num_particles, 0));
        $this->global_best_position = $this->particles[0]->position;
        $this->global_best_score = $this->particles[0]->best_score;
    }

    public function update_global_best() {
        foreach ($this->particles as $particle) {
            if ($particle->best_score < $this->global_best_score) {
                $this->global_best_score = $particle->best_score;
                $this->global_best_position = $particle->best_position;
            }
        }
    }

    public function iterate($objective_function) {
        foreach ($this->particles as $particle) {
            $particle->update_velocity($this->global_best_position);
            $particle->update_position($objective_function->bounds);
            $particle->evaluate($objective_function);
        }
        $this->update_global_best();
    }
}

class ObjectiveFunction {
    public $bounds;

    public function __construct($bounds) {
        $this->bounds = $bounds;
    }

    public function __invoke($position) {
        $x = $position[0];
        $y = $position[1];
        return pow($x ** 2 + $y - 11, 2) + pow($x + $y ** 2 - 7, 2);
    }
}

function main() {
    $dimensions = 2;
    $num_particles = 30;
    $bounds = [-5, 5];
    $objective_function = new ObjectiveFunction($bounds);
    $swarm = new Swarm($num_particles, $dimensions, $bounds);
    for ($i = 0; $i < 100; $i++) {
        $swarm->iterate($objective_function);
        if ($swarm->global_best_score < 1e-06) {
            break;
        }
    }
    echo 'Best position: ' . implode(', ', $swarm->global_best_position) . PHP_EOL;
    echo 'Best score: ' . $swarm->global_best_score . PHP_EOL;
}

main();

?>