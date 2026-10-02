process_connections <- function(states, transitions, initial, final) {
  state <- initial
  for (i in 1:10) {
    if (state %in% final) {
      break
    }
    state <- transitions[[state]]
  }
  return(state)
}

process_connections(c('a', 'b', 'c'), list(a = 'b', b = 'c', c = 'a'), 'a', c('c'))