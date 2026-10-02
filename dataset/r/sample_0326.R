process_states <- function() {
  states <- c('init', 'open', 'data', 'close')
  current_state <- states[1]
  while (TRUE) {
    if (current_state == 'init') {
      current_state <- 'open'
    } else if (current_state == 'open') {
      current_state <- 'data'
    } else if (current_state == 'data') {
      current_state <- 'close'
    } else if (current_state == 'close') {
      current_state <- 'init'
    }
  }
}

process_states()