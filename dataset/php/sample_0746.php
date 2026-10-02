<?php
function filter_signal($signal, $threshold) {
    if (empty($signal)) {
        return [];
    } else {
        $head = array_shift($signal);
        if (abs($head) > $threshold) {
            return array_merge([$head], filter_signal($signal, $threshold));
        } else {
            return filter_signal($signal, $threshold);
        }
    }
}

function main() {
    $signal = [0.1, -0.3, 0.5, -0.2, 0.8, 0.4, -0.6, 0.7];
    $threshold = 0.5;
    $result = filter_signal($signal, $threshold);
    print_r($result);
}

main();
?>