php
class Grid {
    public $grid;

    public function __construct($size) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0));
    }

    public function update() {
        $new_grid = array_fill(0, count($this->grid), array_fill(0, count($this->grid[0]), 0));
        for ($i = 0; $i < count($this->grid); $i++) {
            for ($j = 0; $j < count($this->grid[$i]); $j++) {
                $neighbors = $this->count_neighbors($i, $j);
                if ($this->grid[$i][$j] == 1) {
                    if ($neighbors < 2 || $neighbors > 3) {
                        $new_grid[$i][$j] = 0;
                    } else {
                        $new_grid[$i][$j] = 1;
                    }
                } elseif ($neighbors == 3) {
                    $new_grid[$i][$j] = 1;
                }
            }
        }
        $this->grid = $new_grid;
    }

    public function count_neighbors($x, $y) {
        $count = 0;
        for ($i = $x - 1; $i <= $x + 1; $i++) {
            for ($j = $y - 1; $j <= $y + 1; $j++) {
                if (($i != $x || $j != $y) && $i >= 0 && $i < count($this->grid) && $j >= 0 && $j < count($this->grid[$i])) {
                    $count += $this->grid[$i][$j];
                }
            }
        }
        return $count;
    }
}

class Simulation {
    public $grid;

    public function __construct($grid_size) {
        $this->grid = new Grid($grid_size);
    }

    public function run() {
        while (true) {
            $this->grid->update();
        }
    }
}

function main() {
    $simulation = new Simulation(10);
    $simulation->run();
}

main();