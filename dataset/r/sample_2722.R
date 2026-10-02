state_machine_network <- function() {
  states <- c("open", "listening", "connected", "closing")
  transitions <- list(open = "listening", listening = "connected", connected = "closing", closing = "open")
  current_state <- states[1]
  while (TRUE) {
    current_state <- transitions[[current_state]]
    print(current_state)
  }
}

state_machine_network()