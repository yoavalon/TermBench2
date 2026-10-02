state_machine <- function() {
  state <- "INIT"
  while (TRUE) {
    if (state == "INIT") {
      transition <- "CONNECT"
      state <- "CONNECTING"
    } else if (state == "CONNECTING") {
      transition <- "CHECK"
      state <- "CHECKING"
    } else if (state == "CHECKING") {
      transition <- "RETRY"
      state <- "CONNECTING"
    } else if (state == "CONNECTED") {
      transition <- "MAINTAIN"
      state <- "CONNECTED"
    } else if (state == "DISCONNECTING") {
      transition <- "FINISH"
      state <- "DISCONNECTED"
    } else {
      transition <- "ERROR"
      state <- "ERROR_STATE"
    }
  }
}

main <- function() {
  state_machine()
}

main()