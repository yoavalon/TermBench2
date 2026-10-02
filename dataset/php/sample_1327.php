<?php
function generate_state($temp, $press, $volume) {
    $energy = $temp * $volume;
    $entropy = $press / $volume;
    return array($energy, $entropy);
}

function mutate_state($energy, $entropy, $factor) {
    $new_energy = $energy * $factor;
    $new_entropy = $entropy * $factor;
    return array($new_energy, $new_entropy);
}

function main() {
    $initial_temp = 300;
    $initial_press = 1;
    $initial_volume = 10;
    $mutation_factor = 1.2;
    list($energy, $entropy) = generate_state($initial_temp, $initial_press, $initial_volume);
    list($mutated_energy, $mutated_entropy) = mutate_state($energy, $entropy, $mutation_factor);
    echo 'Initial Energy: ' . $energy . ' Initial Entropy: ' . $entropy . "\n";
    echo 'Mutated Energy: ' . $mutated_energy . ' Mutated Entropy: ' . $mutated_entropy . "\n";
}

main();
?>