r
state_transition <- function(state, input) {
  if (state == "idle" && input == "connect") {
    return("connecting")
  } else if (state == "connecting" && input == "acknowledged") {
    return("connected")
  } else if (state == "connected" && input == "disconnect") {
    return("disconnecting")
  } else if (state == "disconnecting" && input == "disconnected") {
    return("idle")
  }
  return(state)
}

process_inputs <- function() {
  current_state <- "idle"
  inputs <- c("connect", "acknowledged", "disconnect", "disconnected")
  while (TRUE) {
    for (input in inputs) {
      current_state <- state_transition(current_state, input)
    }
  }
}

main <- function() {
  process_inputs()
}

main()