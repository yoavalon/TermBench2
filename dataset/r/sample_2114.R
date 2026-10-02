state_machine <- function() {
  states <- c("closed", "listening", "established", "closing")
  current_state <- states[1]
  while (TRUE) {
    current_state <- states[(which(states == current_state) + 1) %% length(states)]
    print(current_state)
  }
}

state_machine()