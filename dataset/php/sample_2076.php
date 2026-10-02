<?php

class FrameSequenceTracker {

    function __construct($precision) {
        $this->precision = $precision;
        $this->sequence = [];
    }

    function add_frame($timestamp, $value) {
        $this->sequence[] = array($timestamp, round($value, $this->precision));
    }

    function calculate_difference() {
        $differences = [];
        for ($i = 1; $i < count($this->sequence); $i++) {
            $prev_value = $this->sequence[$i - 1][1];
            $curr_value = $this->sequence[$i][1];
            $differences[] = abs($curr_value - $prev_value);
        }
        return $differences;
    }

    function analyze() {
        $differences = $this->calculate_difference();
        $max_diff = !empty($differences) ? max($differences) : 0;
        $min_diff = !empty($differences) ? min($differences) : 0;
        $avg_diff = !empty($differences) ? array_sum($differences) / count($differences) : 0;
        return array($max_diff, $min_diff, $avg_diff);
    }
}

function generate_sequence($tracker, $start, $end, $step) {
    $timestamp = $start;
    while ($timestamp <= $end) {
        $value = $timestamp * 0.123456789;
        $tracker->add_frame($timestamp, $value);
        $timestamp += $step;
    }
}

function main() {
    $tracker = new FrameSequenceTracker(5);
    generate_sequence($tracker, 0, 100, 1);
    list($max_diff, $min_diff, $avg_diff) = $tracker->analyze();
    echo "Max Difference: $max_diff, Min Difference: $min_diff, Average Difference: $avg_diff\n";
}

main();
?>