<?php
function track_sequence($precision, $steps) {
    $data = array(0.0);
    for ($i = 0; $i < $steps; $i++) {
        $next_value = $data[count($data) - 1] + 1.0 / ($i + 1);
        $data[] = round($next_value, $precision);
    }
    return $data;
}

function main() {
    $result = track_sequence(5, 100);
    print_r($result);
}

main();
?>