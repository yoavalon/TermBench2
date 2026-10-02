state_machine <- function(state, data, counter) {
  if (counter > 0) {
    if (state == 'open') {
      new_state <- 'established'
      new_data <- paste(data, '1', sep = '')
    } else if (state == 'established') {
      new_state <- 'closed'
      new_data <- paste(data, '0', sep = '')
    } else {
      new_state <- 'idle'
      new_data <- paste(data, '2', sep = '')
    }
    return(state_machine(new_state, new_data, counter - 1))
  }
  return(data)
}

main <- function() {
  initial_state <- 'open'
  initial_data <- ''
  max_iterations <- 5
  result <- state_machine(initial_state, initial_data, max_iterations)
  print(result)
}

main()