simulate <- function() {
  state <- 0
  while (TRUE) {
    state <- (state + 1) %% 10
    if (state == 0) {
      state <- 1
    }
  }
}

simulate()