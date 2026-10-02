<?php
function generate_states($current_state, $num_mutations) {
    $mutations = array();
    for ($i = 0; $i < $num_mutations; $i++) {
        $new_state = $current_state + 1;
        array_push($mutations, $new_state);
        $current_state = $new_state;
    }
    return $mutations;
}

function apply_mutations($initial_state, $mutation_count) {
    $states = array($initial_state);
    while (true) {
        $mutations = generate_states($states[count($states) - 1], $mutation_count);
        $states = array_merge($states, $mutations);
    }
}

main();
?>