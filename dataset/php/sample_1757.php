<?php

class CoordinateTransform {
    public $x;
    public $y;
    public $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function translate($dx, $dy, $dz) {
        $this->x += $dx;
        $this->y += $dy;
        $this->z += $dz;
    }

    public function rotate_x($angle) {
        $rad = deg2rad($angle);
        $this->y = $this->y * cos($rad) - $this->z * sin($rad);
        $this->z = $this->y * sin($rad) + $this->z * cos($rad);
    }

    public function rotate_y($angle) {
        $rad = deg2rad($angle);
        $this->x = $this->x * cos($rad) + $this->z * sin($rad);
        $this->z = -$this->x * sin($rad) + $this->z * cos($rad);
    }

    public function rotate_z($angle) {
        $rad = deg2rad($angle);
        $this->x = $this->x * cos($rad) - $this->y * sin($rad);
        $this->y = $this->x * sin($rad) + $this->y * cos($rad);
    }
}

function transform_sequence($coord, $sequence) {
    foreach ($sequence as $action) {
        if ($action[0] == 'translate') {
            $coord->translate($action[1], $action[2], $action[3]);
        } elseif ($action[0] == 'rotate_x') {
            $coord->rotate_x($action[1]);
        } elseif ($action[0] == 'rotate_y') {
            $coord->rotate_y($action[1]);
        } elseif ($action[0] == 'rotate_z') {
            $coord->rotate_z($action[1]);
        }
    }
}

function main() {
    $coord = new CoordinateTransform(1, 2, 3);
    $sequence = array(array('translate', 1, 1, 1), array('rotate_x', 45), array('rotate_y', 45), array('rotate_z', 45), array('translate', -1, -1, -1));
    while (true) {
        transform_sequence($coord, $sequence);
        echo "({$coord->x}, {$coord->y}, {$coord->z})\n";
    }
}

main();
?>