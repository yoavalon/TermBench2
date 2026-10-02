def non_terminating_function(x):
    while True:
        x = (x + 1) % 100
non_terminating_function(0)