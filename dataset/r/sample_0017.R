state_machine <- function(data) {
  states <- list(init = 0, open = 1, close = 2)
  current <- states$init
  transitions <- list(states$init = states$open, states$open = states$close, states$close = states$open)
  
  for (packet in data) {
    current <- transitions[[current]]
    if (current == states$close) {
      return(current)
    }
  }
  return(current)
}

state_machine(c('packet1', 'packet2', 'packet3'))