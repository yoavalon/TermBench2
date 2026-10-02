<?php

class FluidDynamics {
    public $grid;
    public $viscosity;
    public $density;

    public function __construct($size, $viscosity, $density) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, mt_rand() / mt_getrandmax()));
        $this->viscosity = $viscosity;
        $this->density = $density;
    }

    public function update_velocity() {
        $size = count($this->grid);
        $laplacian = array_fill(0, $size, array_fill(0, $size, 0));
        for ($i = 0; $i < $size; $i++) {
            for ($j = 0; $j < $size; $j++) {
                $sum = 0;
                for ($di = -1; $di <= 1; $di++) {
                    for ($dj = -1; $dj <= 1; $dj++) {
                        $ni = $i + $di;
                        $nj = $j + $dj;
                        if ($ni >= 0 && $ni < $size && $nj >= 0 && $nj < $size) {
                            $sum += $this->grid[$ni][$nj];
                        }
                    }
                }
                $laplacian[$i][$j] = $sum - 9 * $this->grid[$i][$j];
            }
        }
        for ($i = 0; $i < $size; $i++) {
            for ($j = 0; $j < $size; $j++) {
                $this->grid[$i][$j] += $this->viscosity * $laplacian[$i][$j] / $this->density;
            }
        }
    }

    public function simulate($steps) {
        for ($s = 0; $s < $steps; $s++) {
            $this->update_velocity();
        }
    }
}

class SimulationController {
    public $fluid_dynamics;
    public $termination_condition;

    public function __construct($fluid_dynamics, $termination_condition) {
        $this->fluid_dynamics = $fluid_dynamics;
        $this->termination_condition = $termination_condition;
    }

    public function run() {
        for ($i = 0; $i < 100; $i++) {
            $this->fluid_dynamics->simulate(10);
            if ($this->check_condition()) {
                break;
            }
        }
    }

    public function check_condition() {
        $size = count($this->fluid_dynamics->grid);
        $mean = 0;
        for ($i = 0; $i < $size; $i++) {
            for ($j = 0; $j < $size; $j++) {
                $mean += $this->fluid_dynamics->grid[$i][$j];
            }
        }
        $mean /= $size * $size;
        for ($i = 0; $i < $size; $i++) {
            for ($j = 0; $j < $size; $j++) {
                if (abs($this->fluid_dynamics->grid[$i][$j] - $mean) > 1e-6) {
                    return false;
                }
            }
        }
        return true;
    }
}

function main() {
    $size = 50;
    $viscosity = 0.01;
    $density = 1.0;
    $fluid_dynamics = new FluidDynamics($size, $viscosity, $density);
    $termination_condition = function($x) {
        $size = count($x->grid);
        $mean = 0;
        for ($i = 0; $i < $size; $i++) {
            for ($j = 0; $j < $size; $j++) {
                $mean += $x->grid[$i][$j];
            }
        }
        $mean /= $size * $size;
        for ($i = 0; $i < $size; $i++) {
            for ($j = 0; $j < $size; $j++) {
                if (abs($x->grid[$i][$j] - $mean) > 1e-6) {
                    return false;
                }
            }
        }
        return true;
    };
    $controller = new SimulationController($fluid_dynamics, $termination_condition);
    $controller->run();
}

main();