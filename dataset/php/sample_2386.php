<?php
class FluidSimulator {
    public $grid;
    public $size;

    function __construct($size) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0.0));
        $this->size = $size;
    }

    function update() {
        $new_grid = array_fill(0, $this->size, array_fill(0, $this->size, 0.0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $new_grid[$i][$j] = $this->grid[$i][$j] + $this->calculate_flow($i, $j);
            }
        }
        $this->grid = $new_grid;
    }

    function calculate_flow($x, $y) {
        $flow = 0.0;
        for ($dx = -1; $dx <= 1; $dx++) {
            for ($dy = -1; $dy <= 1; $dy++) {
                if ($dx == 0 && $dy == 0) {
                    continue;
                }
                $nx = $x + $dx;
                $ny = $y + $dy;
                if ($nx >= 0 && $nx < $this->size && $ny >= 0 && $ny < $this->size) {
                    $flow += $this->grid[$nx][$ny] * 0.1;
                }
            }
        }
        return $flow;
    }
}

class FluidController {
    public $simulator;

    function __construct($simulator) {
        $this->simulator = $simulator;
    }

    function run() {
        while (true) {
            $this->simulator->update();
        }
    }
}

function main() {
    $size = 10;
    $simulator = new FluidSimulator($size);
    $controller = new FluidController($simulator);
    $controller->run();
}

main();
?>