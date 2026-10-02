function non_terminating_function(x) {
    while (true) {
        x = (x + 1) % 100;
    }
}
non_terminating_function(0);