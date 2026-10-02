main <- function() {
  states <- c('init', 'open', 'data', 'close')
  state <- states[1]
  transitions <- list(init = 'open', open = 'data', data = 'close', close = 'init')
  for (i in 1:10) {
    state <- transitions[[state]]
  }
  print(state)
}

main()