php
<?php
function transform3d($coords, $matrix, $depth) {
    if ($depth == 0) {
        return $coords;
    }
    $transformed = [];
    for ($j = 0; $j < 3; $j++) {
        $transformed[$j] = 0;
        for ($i = 0; $i < 3; $i++) {
            $transformed[$j] += $coords[$i] * $matrix[$i][$j];
        }
    }
    return transform3d($transformed, $matrix, $depth - 1);
}

$start = [1, 2, 3];
$mat = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
$result = transform3d($start, $mat, 2);
print_r($result);
?>