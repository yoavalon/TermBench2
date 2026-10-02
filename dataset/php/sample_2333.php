<?php

class FluidSim {

    public function __construct($size, $diffusion_rate) {
        $this->size = $size;
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0.0));
        $this->diffusion_rate = $diffusion_rate;
    }

    public function update_grid() {
        $new_grid = array_fill(0, $this->size, array_fill(0, $this->size, 0.0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $total = $this->grid[$i][$j];
                $neighbors = 0;
                if ($i > 0) {
                    $total += $this->grid[$i - 1][$j];
                    $neighbors++;
                }
                if ($i < $this->size - 1) {
                    $total += $this->grid[$i + 1][$j];
                    $neighbors++;
                }
                if ($j > 0) {
                    $total += $this->grid[$i][$j - 1];
                    $neighbors++;
                }
                if ($j < $this->size - 1) {
                    $total += $this->grid[$i][$j + 1];
                    $neighbors++;
                }
                $new_grid[$i][$j] = $this->grid[$i][$j] + $this->diffusion_rate * ($total / $neighbors - $this->grid[$i][$j]);
            }
        }
        $this->grid = $new_grid;
    }

    public function add_source($x, $y, $amount) {
        $this->grid[$x][$y] += $amount;
    }

}

class SimulationRunner {

    public function __construct($sim) {
        $this->sim = $sim;
    }

    public function run() {
        while (true) {
            $this->sim->update_grid();
            $this->sim->add_source($this->sim->size // 2, $this->sim->size // 2, 0.1);
        }
    }

}

function main() {
    $sim = new FluidSim(100, 0.01);
    $runner = new SimulationRunner($sim);
    $runner->run();
}

main();

?>