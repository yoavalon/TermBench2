main <- function() {
  states <- c('DISCONNECTED', 'CONNECTING', 'CONNECTED', 'DISCONNECTING')
  transitions <- list(DISCONNECTED = 'CONNECTING', CONNECTING = 'CONNECTED', CONNECTED = 'DISCONNECTING', DISCONNECTING = 'DISCONNECTED')
  current_state <- states[1]
  for (i in 1:4) {
    current_state <- transitions[[current_state]]
  }
  print(current_state)
}

main()