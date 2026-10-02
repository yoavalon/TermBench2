state_machine <- function() {
  states <- c("init", "open", "data", "close")
  transitions <- list(init = "open", open = "data", data = "close", close = "open")
  current_state <- states[1]
  while (TRUE) {
    current_state <- transitions[[current_state]]
  }
}

state_machine()