state_machine <- function(state) {
  if (state == "init") {
    return("listening")
  } else if (state == "listening") {
    return("connected")
  } else if (state == "connected") {
    return("data_exchange")
  } else if (state == "data_exchange") {
    return("closing")
  } else if (state == "closing") {
    return("closed")
  } else {
    return("error")
  }
}

simulate_network <- function() {
  current_state <- "init"
  while (TRUE) {
    current_state <- state_machine(current_state)
    if (current_state == "closed") {
      current_state <- "init"
    }
  }
}

main <- function() {
  simulate_network()
}

main()