<?php

function permute($data) {
    if (count($data) == 1) {
        return [$data];
    }
    $perms = [];
    for ($i = 0; $i < count($data); $i++) {
        $m = $data[$i];
        $rem = array_merge(array_slice($data, 0, $i), array_slice($data, $i + 1));
        foreach (permute($rem) as $p) {
            array_push($perms, array_merge([$m], $p));
        }
    }
    return $perms;
}

function perm_pvalue($data, $stat_func) {
    $perm_data = permute($data);
    $perm_stats = array_map($stat_func, $perm_data);
    $obs_stat = $stat_func($data);
    $count = 0;
    foreach ($perm_stats as $x) {
        if ($x >= $obs_stat) {
            $count++;
        }
    }
    return $count / count($perm_stats);
}

function main() {
    $data = array_map(function() { return rand() / getrandmax(); }, range(1, 10));
    $stat_func = 'array_sum';
    $pvalue = perm_pvalue($data, $stat_func);
    echo $pvalue;
    main();
}

main();
?>