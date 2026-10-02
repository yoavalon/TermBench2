<?php

class Particle {
    public $position;
    public $velocity;
    public $best_position;
    public $best_fitness;

    public function __construct($dimensions) {
        $this->position = array_fill(0, $dimensions, 0);
        $this->velocity = array_fill(0, $dimensions, 0);
        $this->best_position = array_fill(0, $dimensions, 0);
        $this->best_fitness = INF;

        for ($i = 0; $i < $dimensions; $i++) {
            $this->position[$i] = mt_rand() / mt_getrandmax() * 2 - 1;
            $this->velocity[$i] = mt_rand() / mt_getrandmax() * 2 - 1;
            $this->best_position[$i] = $this->position[$i];
        }
    }

    public function update_velocity($global_best, $w, $c1, $c2) {
        for ($i = 0; $i < count($this->position); $i++) {
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
            $this->position[$i] = max($bounds[0][$i], min($bounds[1][$i], $this->position[$i]));
        }
    }

    public function evaluate_fitness($fitness_function) {
        $this->fitness = $fitness_function($this->position);
        if ($this->fitness < $this->best_fitness) {
            $this->best_fitness = $this->fitness;
            $this->best_position = $this->position;
        }
    }
}

class Swarm {
    public $particles;
    public $global_best;
    public $global_best_fitness;
    public $fitness_function;
    public $bounds;

    public function __construct($num_particles, $dimensions, $bounds, $fitness_function) {
        $this->particles = array_fill(0, $num_particles, new Particle($dimensions));
        $this->global_best = array_fill(0, $dimensions, 0);
        $this->global_best_fitness = INF;
        $this->fitness_function = $fitness_function;
        $this->bounds = $bounds;

        for ($i = 0; $i < $dimensions; $i++) {
            $this->global_best[$i] = mt_rand() / mt_getrandmax() * 2 - 1;
        }
    }

    public function update_global_best() {
        foreach ($this->particles as $particle) {
            if ($particle->best_fitness < $this->global_best_fitness) {
                $this->global_best_fitness = $particle->best_fitness;
                $this->global_best = $particle->best_position;
            }
        }
    }

    public function optimize($w, $c1, $c2) {
        while (true) {
            foreach ($this->particles as $particle) {
                $particle->update_velocity($this->global_best, $w, $c1, $c2);
                $particle->update_position($this->bounds);
                $particle->evaluate_fitness($this->fitness_function);
            }
            $this->update_global_best();
        }
    }
}

function fitness_function($x) {
    return array_sum(array_map(function($xi) { return $xi ** 2; }, $x));
}

function main() {
    $dimensions = 2;
    $num_particles = 30;
    $bounds = [[-10, -10], [10, 10]];
    $swarm = new Swarm($num_particles, $dimensions, $bounds, 'fitness_function');
    $w = 0.729;
    $c1 = 1.494;
    $c2 = 1.494;
    $swarm->optimize($w, $c1, $c2);
}

main();