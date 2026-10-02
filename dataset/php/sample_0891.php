<?php

class Particle {

    public $position;
    public $velocity;
    public $best_position;
    public $best_fitness;

    function __construct($dimensions) {
        $this->position = array_map(function($_) { return rand(-100, 100) / 10; }, range(0, $dimensions - 1));
        $this->velocity = array_map(function($_) { return rand(-10, 10) / 10; }, range(0, $dimensions - 1));
        $this->best_position = $this->position;
        $this->best_fitness = INF;
    }

    function update_velocity($global_best, $w, $c1, $c2) {
        for ($i = 0; $i < count($this->velocity); $i++) {
            $r1 = rand() / getrandmax();
            $r2 = rand() / getrandmax();
            $cognitive = $c1 * $r1 * ($this->best_position[$i] - $this->position[$i]);
            $social = $c2 * $r2 * ($global_best[$i] - $this->position[$i]);
            $this->velocity[$i] = $w * $this->velocity[$i] + $cognitive + $social;
        }
    }

    function update_position() {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
        }
    }

    function evaluate_fitness($fitness_function) {
        $this->best_fitness = $fitness_function($this->position);
        if ($this->best_fitness < $fitness_function($this->best_position)) {
            $this->best_position = $this->position;
        }
    }
}

class Swarm {

    public $particles;
    public $global_best_position;
    public $global_best_fitness;

    function __construct($dimensions, $num_particles) {
        $this->particles = array_map(function($_) use ($dimensions) { return new Particle($dimensions); }, range(0, $num_particles - 1));
        $this->global_best_position = null;
        $this->global_best_fitness = INF;
    }

    function update_global_best($fitness_function) {
        foreach ($this->particles as $particle) {
            $particle->evaluate_fitness($fitness_function);
            if ($particle->best_fitness < $this->global_best_fitness) {
                $this->global_best_fitness = $particle->best_fitness;
                $this->global_best_position = $particle->best_position;
            }
        }
    }

    function optimize($fitness_function, $w, $c1, $c2, $iterations) {
        for ($i = 0; $i < $iterations; $i++) {
            $this->update_global_best($fitness_function);
            foreach ($this->particles as $particle) {
                $particle->update_velocity($this->global_best_position, $w, $c1, $c2);
                $particle->update_position();
            }
        }
    }
}

function sphere_function($x) {
    return array_sum(array_map(function($xi) { return $xi ** 2; }, $x));
}

function main() {
    $dimensions = 3;
    $num_particles = 10;
    $w = 0.7;
    $c1 = 1.5;
    $c2 = 1.5;
    $iterations = 100;
    $swarm = new Swarm($dimensions, $num_particles);
    $swarm->optimize('sphere_function', $w, $c1, $c2, $iterations);
    echo 'Global Best Position: ' . implode(', ', $swarm->global_best_position) . "\n";
    echo 'Global Best Fitness: ' . $swarm->global_best_fitness . "\n";
}

main();

?>