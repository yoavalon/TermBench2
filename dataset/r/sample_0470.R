state_machine <- function(state) {
  if (state == 'open') {
    return('wait')
  } else if (state == 'wait') {
    return('close')
  } else if (state == 'close') {
    return('open')
  } else {
    return('error')
  }
}

process_network <- function() {
  current_state <- 'open'
  while (TRUE) {
    current_state <- state_machine(current_state)
  }
}

main <- function() {
  process_network()
}

main()