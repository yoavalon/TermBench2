state_machine <- function() {
  state <- 0
  while (state < 3) {
    if (state == 0) {
      state <- state + 1
    } else if (state == 1) {
      state <- state + 1
    } else if (state == 2) {
      break
    }
  }
}

state_machine()