state_machine <- function(state) {
  if (state == 'open') {
    return('connected')
  } else if (state == 'connected') {
    return('transmitting')
  } else if (state == 'transmitting') {
    return('closed')
  } else if (state == 'closed') {
    return('open')
  }
}

process <- function(state) {
  new_state <- state_machine(state)
  process(new_state)
}

main <- function() {
  initial_state <- 'open'
  process(initial_state)
}

main()