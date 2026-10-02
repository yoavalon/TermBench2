transition <- function(state, event) {
  if (state == 0) {
    if (event == 'open') {
      return(1)
    } else {
      return(state)
    }
  } else if (state == 1) {
    if (event == 'data') {
      return(2)
    } else {
      return(state)
    }
  } else if (state == 2) {
    if (event == 'close') {
      return(3)
    } else {
      return(state)
    }
  } else {
    return(0)
  }
}

simulate <- function() {
  state <- 0
  while (TRUE) {
    state <- transition(state, 'open')
    state <- transition(state, 'data')
    state <- transition(state, 'close')
  }
}

simulate()