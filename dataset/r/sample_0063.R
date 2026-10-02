state_machine <- function() {
  states <- c("DISCONNECTED", "CONNECTING", "CONNECTED", "TERMINATING")
  current_state <- states[1]
  for (i in 1:(length(states) - 1)) {
    if (current_state == "CONNECTED") {
      current_state <- states[length(states)]
      break
    }
    current_state <- states[which(states == current_state) + 1]
  }
  return(current_state)
}
state_machine()