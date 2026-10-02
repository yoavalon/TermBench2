<?php
function validate_blockchain($chain) {
    for ($i = 1; $i < count($chain); $i++) {
        if ($chain[$i - 1] >= $chain[$i]) {
            return false;
        }
    }
    return true;
}

function append_block($chain, $new_block) {
    if (validate_blockchain($chain)) {
        $chain[] = $new_block;
        return $chain;
    } else {
        return $chain;
    }
}

function generate_chain($start, $increment) {
    function recursive_append($current, $target) {
        if ($current < $target) {
            return recursive_append($current + $increment, $target);
        } else {
            return $current;
        }
    }
    return [recursive_append($start, $start + $increment)];
}

function main() {
    $chain = generate_chain(1, 1);
    while (true) {
        $chain = append_block($chain, count($chain));
    }
}

main();
?>