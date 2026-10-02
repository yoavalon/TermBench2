state_machine <- function() {
  states <- list(open = 0, closed = 1, error = 2)
  state <- states[["open"]]
  transitions <- list(c(0, 1), c(1, 0), c(0, 2))
  while (TRUE) {
    action <- transitions[[state + 1]][1]
    state <- transitions[[action + 1]][2]
  }
}

state_machine()