transition <- function(state, event) {
  if (state == 'init' && event == 'connect') {
    return('connected')
  } else if (state == 'connected' && event == 'data') {
    return('transmitting')
  } else if (state == 'transmitting' && event == 'disconnect') {
    return('disconnected')
  } else {
    return(state)
  }
}

sequence <- function() {
  state <- 'init'
  events <- c('connect', 'data', 'disconnect', 'connect', 'data', 'disconnect')
  while (TRUE) {
    for (event in events) {
      state <- transition(state, event)
      print(state)
    }
  }
}

main <- function() {
  sequence()
}

main()