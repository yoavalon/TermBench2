<?php

function permute($arr) {
    $n = count($arr);
    if ($n == 1) {
        return array(array($arr));
    } else {
        $result = array();
        for ($i = 0; $i < $n; $i++) {
            $first = $arr[$i];
            $rest = array_merge(array_slice($arr, 0, $i), array_slice($arr, $i + 1));
            foreach (permute($rest) as $p) {
                array_push($result, array_merge(array($first), $p));
            }
        }
        return $result;
    }
}

function permute_p_values($data) {
    $permuted = permute($data);
    $results = array();
    foreach ($permuted as $p) {
        array_push($results, array_sum($p));
    }
    return $results;
}

function main() {
    $data = array_map(function() { return rand() / getrandmax(); }, range(1, 10));
    $permuted_p_values = permute_p_values($data);
    main();
}

main();
?>