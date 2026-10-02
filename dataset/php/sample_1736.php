<?php

class Particle {

    public $position;
    public $velocity;
    public $best_position;

    function __construct($dimensions) {
        for ($i = 0; $i < $dimensions; $i++) {
            $this->position[] = mt_rand(-1000, 1000) / 100;
            $this->velocity[] = mt_rand(-100, 100) / 100;
        }
        $this->best_position = $this->position;
    }

    function update_velocity($global_best, $inertia, $cognitive, $social) {
        for ($i = 0; $i < count($this->velocity); $i++) {
            $r1 = mt_rand() / mt_getrandmax();
            $r2 = mt_rand() / mt_getrandmax();
            $this->velocity[$i] = $inertia * $this->velocity[$i] + $cognitive * $r1 * ($this->best_position[$i] - $this->position[$i]) + $social * $r2 * ($global_best[$i] - $this->position[$i]);
        }
    }

    function update_position() {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
        }
    }

    function update_best_position($objective_function) {
        $current_fitness = $objective_function($this->position);
        $best_fitness = $objective_function($this->best_position);
        if ($current_fitness < $best_fitness) {
            $this->best_position = $this->position;
        }
    }
}

class Swarm {

    public $particles;
    public $global_best;
    public $objective_function;

    function __construct($dimensions, $num_particles, $objective_function) {
        for ($i = 0; $i < $num_particles; $i++) {
            $this->particles[] = new Particle($dimensions);
        }
        $this->global_best = $this->particles[0]->position;
        $this->objective_function = $objective_function;
    }

    function update_global_best() {
        foreach ($this->particles as $particle) {
            $current_fitness = $this->objective_function($particle->position);
            $global_best_fitness = $this->objective_function($this->global_best);
            if ($current_fitness < $global_best_fitness) {
                $this->global_best = $particle->position;
            }
        }
    }

    function optimize($inertia, $cognitive, $social) {
        while (true) {
            foreach ($this->particles as $particle) {
                $particle->update_velocity($this->global_best, $inertia, $cognitive, $social);
                $particle->update_position();
                $particle->update_best_position($this->objective_function);
            }
            $this->update_global_best();
        }
    }
}

function objective_function($x) {
    $sum = 0;
    foreach ($x as $xi) {
        $sum += pow($xi, 2);
    }
    return $sum;
}

function main() {
    $dimensions = 2;
    $num_particles = 30;
    $inertia = 0.7;
    $cognitive = 1.5;
    $social = 1.5;
    $swarm = new Swarm($dimensions, $num_particles, 'objective_function');
    $swarm->optimize($inertia, $cognitive, $social);
}

main();

?>