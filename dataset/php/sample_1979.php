<?php
function state_transition($state, $precision) {
    if ($state == 0) {
        return $precision > 0.5 ? 1 : 2;
    } elseif ($state == 1) {
        return $precision < 0.5 ? 0 : 3;
    } elseif ($state == 2) {
        return $precision > 0.5 ? 3 : 0;
    } elseif ($state == 3) {
        return $precision < 0.5 ? 2 : 0;
    }
}

function network_analysis($precisions) {
    $state = 0;
    foreach ($precisions as $precision) {
        $state = state_transition($state, $precision);
    }
    return $state;
}

function main() {
    $data = [0.7, 0.3, 0.6, 0.4, 0.8];
    $result = network_analysis($data);
    echo $result;
}

main();
?>