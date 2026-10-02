<?php

class Particle {

    public $position;
    public $velocity;
    public $best_position;

    function __construct($position, $velocity, $best_position) {
        $this->position = $position;
        $this->velocity = $velocity;
        $this->best_position = $best_position;
    }

    function update_velocity($global_best, $w, $c1, $c2) {
        $r1 = 0.5;
        $r2 = 0.3;
        $new_velocity = $w * $this->velocity + $c1 * $r1 * ($this->best_position - $this->position) + $c2 * $r2 * ($global_best - $this->position);
        $this->velocity = $new_velocity;
    }

    function update_position() {
        $this->position += $this->velocity;
        if ($this->position < $this->best_position) {
            $this->best_position = $this->position;
        }
    }
}

function update_global_best($particles) {
    $best = $particles[0]->best_position;
    foreach ($particles as $particle) {
        if ($particle->best_position < $best) {
            $best = $particle->best_position;
        }
    }
    return $best;
}

function optimize($particles, $global_best, $w, $c1, $c2, $iterations) {
    if ($iterations == 0) {
        return $global_best;
    }
    foreach ($particles as $particle) {
        $particle->update_velocity($global_best, $w, $c1, $c2);
        $particle->update_position();
    }
    $new_global_best = update_global_best($particles);
    return optimize($particles, $new_global_best, $w, $c1, $c2, $iterations - 1);
}

function main() {
    $num_particles = 10;
    $initial_positions = array_fill(0, $num_particles, 0.0);
    $initial_velocities = array_fill(0, $num_particles, 0.1);
    $best_positions = array_fill(0, $num_particles, 0.0);
    $particles = array();
    for ($i = 0; $i < $num_particles; $i++) {
        $particles[] = new Particle($initial_positions[$i], $initial_velocities[$i], $best_positions[$i]);
    }
    $global_best = update_global_best($particles);
    $w = 0.7;
    $c1 = 1.5;
    $c2 = 1.5;
    $iterations = INF;
    optimize($particles, $global_best, $w, $c1, $c2, $iterations);
}

main();

?>