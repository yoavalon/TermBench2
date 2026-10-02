<?php

class Particle {
    public $position;
    public $velocity;
    public $best_position;
    public $best_fitness;

    function __construct($dimensions) {
        $this->position = array_fill(0, $dimensions, mt_rand() / mt_getrandmax() * 2 - 1);
        $this->velocity = array_fill(0, $dimensions, mt_rand() / mt_getrandmax() * 2 - 1);
        $this->best_position = $this->position;
        $this->best_fitness = INF;
    }
}

class PSO {
    public $dimensions;
    public $population;
    public $gbest_position;
    public $gbest_fitness;
    public $omega;
    public $phi_p;
    public $phi_g;

    function __construct($dimensions, $population_size, $omega, $phi_p, $phi_g) {
        $this->dimensions = $dimensions;
        $this->population = array_fill(0, $population_size, new Particle($dimensions));
        $this->gbest_position = array_fill(0, $dimensions, 0);
        $this->gbest_fitness = INF;
        $this->omega = $omega;
        $this->phi_p = $phi_p;
        $this->phi_g = $phi_g;
    }

    function update_global_best() {
        foreach ($this->population as $particle) {
            $fitness = $this->fitness($particle->position);
            if ($fitness < $particle->best_fitness) {
                $particle->best_fitness = $fitness;
                $particle->best_position = $particle->position;
            }
            if ($fitness < $this->gbest_fitness) {
                $this->gbest_fitness = $fitness;
                $this->gbest_position = $particle->position;
            }
        }
    }

    function update_velocity($particle) {
        for ($i = 0; $i < $this->dimensions; $i++) {
            $r_p = mt_rand() / mt_getrandmax();
            $r_g = mt_rand() / mt_getrandmax();
            $cognitive = $this->phi_p * $r_p * ($particle->best_position[$i] - $particle->position[$i]);
            $social = $this->phi_g * $r_g * ($this->gbest_position[$i] - $particle->position[$i]);
            $particle->velocity[$i] = $this->omega * $particle->velocity[$i] + $cognitive + $social;
        }
    }

    function update_position($particle) {
        for ($i = 0; $i < $this->dimensions; $i++) {
            $particle->position[$i] += $particle->velocity[$i];
        }
    }

    function fitness($position) {
        return array_sum(array_map(function($x) { return $x ** 2; }, $position));
    }

    function run() {
        while (true) {
            $this->update_global_best();
            foreach ($this->population as $particle) {
                $this->update_velocity($particle);
                $this->update_position($particle);
            }
        }
    }
}

function main() {
    $dimensions = 2;
    $population_size = 10;
    $omega = 0.7;
    $phi_p = 1.5;
    $phi_g = 1.5;
    $pso = new PSO($dimensions, $population_size, $omega, $phi_p, $phi_g);
    $pso->run();
}

main();
?>