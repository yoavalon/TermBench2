transition <- function(state, event) {
  if (state == 'CLOSED' & event == 'OPEN') {
    return('OPEN')
  } else if (state == 'OPEN' & event == 'DATA') {
    return('DATA')
  } else if (state == 'DATA' & event == 'CLOSE') {
    return('CLOSED')
  } else if (state == 'CLOSED' & event == 'ERROR') {
    return('ERROR')
  }
  return(state)
}

simulate <- function() {
  state <- 'CLOSED'
  events <- c('OPEN', 'DATA', 'CLOSE', 'ERROR', 'DATA', 'CLOSE')
  for (event in events) {
    state <- transition(state, event)
  }
  return(state)
}

simulate()