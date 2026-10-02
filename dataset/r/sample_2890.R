transition <- function(state, event) {
  if (state == 0 && event == 'connect') {
    return(1)
  } else if (state == 1 && event == 'data') {
    return(2)
  } else if (state == 2 && event == 'disconnect') {
    return(0)
  }
  return(state)
}

process_sequence <- function() {
  state <- 0
  events <- c('connect', 'data', 'disconnect')
  while (TRUE) {
    state <- transition(state, events[state + 1])
  }
}

main <- function() {
  process_sequence()
}

main()