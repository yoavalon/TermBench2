main <- function() {
  states <- c('start', 'open', 'data', 'close', 'end')
  transitions <- list(start = 'open', open = 'data', data = 'close', close = 'end')
  current_state <- 'start'
  while (current_state != 'end') {
    current_state <- transitions[[current_state]]
  }
  return(current_state)
}

if (identical(sys.calls()[[1]], quote(main()))) {
  main()
}