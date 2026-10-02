php
<?php
function cellular_automata($steps, $cells) {
    for ($i = 0; $i < $steps; $i++) {
        $new_cells = array();
        for ($j = 1; $j < count($cells) - 1; $j++) {
            $new_cells[$j] = ($cells[$j - 1] == $cells[$j] && $cells[$j] == $cells[$j + 1]) ? 0 : 1;
        }
        $cells = $new_cells;
    }
    return $cells;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $initial_state = array(0, 1, 0, 1, 1, 0, 0, 1);
    $steps = 5;
    $result = cellular_automata($steps, $initial_state);
    print_r($result);
}
?>