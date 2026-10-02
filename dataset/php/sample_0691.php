<?php
function consensus($state, $threshold, $depth) {
    if ($depth == 0 || array_sum($state) >= $threshold) {
        return $state;
    } else {
        $new_state = array_map(function($x) use ($threshold) {
            return $x < $threshold ? $x + 1 : $x;
        }, $state);
        return consensus($new_state, $threshold, $depth - 1);
    }
}
consensus([0, 0, 0], 5, 3);
?>