<?php
function main() {
    $data = [];
    for ($i = 0; $i < 50; $i++) {
        $data[] = rand(1, 100);
    }
    $optimized = [];
    for ($i = 0; $i < 5; $i++) {
        $max_val = max($data);
        $optimized[] = $max_val;
        $key = array_search($max_val, $data);
        unset($data[$key]);
        $data = array_values($data);
    }
    print_r($optimized);
}
main();
?>