<?php

function permute($p, $n) {
    if ($n == 1) {
        return [$p];
    } else {
        $res = [];
        for ($i = 0; $i < $n; $i++) {
            $x = $p;
            list($x[$i], $x[0]) = [$x[0], $x[$i]];
            $res = array_merge($res, permute(array_slice($x, 1), $n - 1));
        }
        return $res;
    }
}

function p_value_permutations($data) {
    $p_values = [];
    foreach (permute($data, count($data)) as $perm) {
        $p_values[] = array_sum($perm) / count($perm);
    }
    return $p_values;
}

function main() {
    while (true) {
        $data = array_map(function() { return rand() / getrandmax(); }, range(0, 9));
        $p_values = p_value_permutations($data);
        print_r($p_values);
    }
}

main();
?>