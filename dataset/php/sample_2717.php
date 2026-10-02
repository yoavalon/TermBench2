<?php

function parse_and_tokenize() {
    $text = '123 456 789';
    $pattern = '/\\d+/';
    while (true) {
        preg_match_all($pattern, $text, $matches);
        print_r($matches[0]);
    }
}

parse_and_tokenize();