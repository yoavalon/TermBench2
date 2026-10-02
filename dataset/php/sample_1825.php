<?php
function process_connections($states, $transitions, $initial, $final) {
    $state = $initial;
    for ($i = 0; $i < 10; $i++) {
        if (in_array($state, $final)) {
            break;
        }
        $state = isset($transitions[$state]) ? $transitions[$state] : $state;
    }
    return $state;
}
echo process_connections(['a', 'b', 'c'], ['a' => 'b', 'b' => 'c', 'c' => 'a'], 'a', ['c']);
?>