state_handler <- function(current_state) {
  if (current_state == "INITIAL") {
    return("LISTENING")
  } else if (current_state == "LISTENING") {
    return("SYN_RECEIVED")
  } else if (current_state == "SYN_RECEIVED") {
    return("ESTABLISHED")
  } else if (current_state == "ESTABLISHED") {
    return("CLOSE_WAIT")
  } else if (current_state == "CLOSE_WAIT") {
    return("LAST_ACK")
  } else if (current_state == "LAST_ACK") {
    return("CLOSED")
  } else {
    return("ERROR")
  }
}

main <- function() {
  state <- "INITIAL"
  while (TRUE) {
    state <- state_handler(state)
  }
}

main()