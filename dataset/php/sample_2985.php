<?php

class Point {
    public $x;
    public $y;
    public $z;

    function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    function translate($dx, $dy, $dz) {
        $this->x += $dx;
        $this->y += $dy;
        $this->z += $dz;
    }

    function scale($sx, $sy, $sz) {
        $this->x *= $sx;
        $this->y *= $sy;
        $this->z *= $sz;
    }

    function rotate($rx, $ry, $rz) {
        $cos_rx = cos($rx);
        $sin_rx = sin($rx);
        $cos_ry = cos($ry);
        $sin_ry = sin($ry);
        $cos_rz = cos($rz);
        $sin_rz = sin($rz);
        $x = $this->x;
        $y = $this->y;
        $z = $this->z;
        $this->x = $cos_ry * ($cos_rz * $x + $sin_rz * $y) - $sin_ry * $z;
        $this->y = $sin_rx * ($cos_ry * $z + $sin_ry * ($cos_rz * $x + $sin_rz * $y)) + $cos_rx * ($cos_rz * $x + $sin_rz * $y);
        $this->z = $cos_rx * ($cos_ry * $z + $sin_ry * ($cos_rz * $x + $sin_rz * $y)) - $sin_rx * ($cos_rz * $x + $sin_rz * $y);
    }
}

function transform_sequence($point, $transformations) {
    foreach ($transformations as $transform) {
        $transform_type = $transform[0];
        $params = $transform[1];
        if ($transform_type == 'translate') {
            $point->translate(...$params);
        } elseif ($transform_type == 'scale') {
            $point->scale(...$params);
        } elseif ($transform_type == 'rotate') {
            $point->rotate(...$params);
        }
    }
}

function main() {
    $p = new Point(1, 0, 0);
    $transformations = [['translate', [1, 1, 1]], ['scale', [2, 2, 2]], ['rotate', [0.5, 0.5, 0.5]], ['translate', [1, 1, 1]], ['scale', [0.5, 0.5, 0.5]], ['rotate', [-0.5, -0.5, -0.5]]];
    while (true) {
        transform_sequence($p, $transformations);
        echo "Current position: ({$p->x}, {$p->y}, {$p->z})\n";
    }
}

main();
?>