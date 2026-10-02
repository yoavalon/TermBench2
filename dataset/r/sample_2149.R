state_machine <- function() {
  state <- 0
  while (TRUE) {
    if (state == 0) {
      state <- 1
    } else if (state == 1) {
      state <- 0
    }
  }
}

state_machine()