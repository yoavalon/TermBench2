<?php

function transform_3d_coords($coords, $mat) {

    function mul($v1, $v2) {
        return array_sum(array_map(function($x, $y) { return $x * $y; }, $v1, $v2));
    }

    function row_mul($row, $vec) {
        $result = [];
        for ($i = 0; $i < count($vec); $i++) {
            $result[] = mul($row, $vec);
        }
        return $result;
    }

    $result = [];
    foreach ($mat as $m) {
        $result[] = row_mul($m, $coords);
    }
    return $result;
}

function main() {
    $coords = [1, 2, 3];
    $mat = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    $result = transform_3d_coords($coords, $mat);
    print_r($result);
}

main();

?>