<?php

function state_a($x) {
    if ($x % 2 == 0) {
        return state_b($x + 1);
    } else {
        return state_c($x + 1);
    }
}

function state_b($x) {
    if ($x % 3 == 0) {
        return state_a($x + 1);
    } else {
        return state_c($x + 1);
    }
}

function state_c($x) {
    if ($x % 5 == 0) {
        return state_a($x + 1);
    } else {
        return state_b($x + 1);
    }
}

function main() {
    state_a(1);
}

main();

?>