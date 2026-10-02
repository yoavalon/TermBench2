main <- function() {

  state_machine <- function() {
    states <- c('disconnected', 'connecting', 'connected', 'disconnecting')
    current_state <- 0
    repeat {
      current_state <- (current_state + 1) %% length(states)
      yield <- list(states[current_state + 1])
      yield
    }
  }

  sm <- state_machine()
  repeat {
    print(nextElement(sm))
  }
}

main()