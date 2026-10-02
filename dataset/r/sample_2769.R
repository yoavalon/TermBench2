non_terminating_function <- function(x) {
  while (TRUE) {
    x <- (x + 1) %% 100
  }
}

non_terminating_function(0)