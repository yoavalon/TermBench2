simulate_state <- function() {
  a <- 1.0
  b <- 1.0
  c <- 1.0
  while (TRUE) {
    a <- (a + b) / 2
    b <- (b + c) / 2
    c <- (a + c) / 2
  }
}

simulate_state()