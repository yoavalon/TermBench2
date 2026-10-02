r
state_transition <- function(state, event) {
  if (state == "DISCONNECTED") {
    if (event == "CONNECT") {
      return("CONNECTING")
    }
    return("DISCONNECTED")
  }
  if (state == "CONNECTING") {
    if (event == "TIMEOUT") {
      return("DISCONNECTED")
    }
    if (event == "ACKNOWLEDGE") {
      return("CONNECTED")
    }
    return("CONNECTING")
  }
  if (state == "CONNECTED") {
    if (event == "DISCONNECT") {
      return("DISCONNECTING")
    }
    return("CONNECTED")
  }
  if (state == "DISCONNECTING") {
    if (event == "ACKNOWLEDGE") {
      return("DISCONNECTED")
    }
    return("DISCONNECTING")
  }
}

simulate_network <- function() {
  states <- c("DISCONNECTED", "CONNECTING", "CONNECTED", "DISCONNECTING")
  events <- c("CONNECT", "TIMEOUT", "ACKNOWLEDGE", "DISCONNECT")
  current_state <- "DISCONNECTED"
  while (TRUE) {
    current_state <- state_transition(current_state, events[1])
    if (current_state == "CONNECTED") {
      events[1] <- "DISCONNECT"
    } else {
      events[1] <- "CONNECT"
    }
  }
}

simulate_network()