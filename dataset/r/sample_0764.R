process_state <- function(state, data) {
  if (state == 'start') {
    return(list(state = 'open', data = paste(data, 'initiated ')))
  } else if (state == 'open') {
    return(list(state = 'data', data = paste(data, 'transmitting ')))
  } else if (state == 'data') {
    return(list(state = 'close', data = paste(data, 'received ')))
  } else if (state == 'close') {
    return(list(state = 'end', data = paste(data, 'closing ')))
  } else if (state == 'end') {
    return(list(state = 'end', data = data))
  } else {
    stop('Invalid state')
  }
}

state_machine <- function(state, data, steps) {
  if (steps == 0) {
    return(data)
  }
  result <- process_state(state, data)
  new_state <- result$state
  new_data <- result$data
  return(state_machine(new_state, new_data, steps - 1))
}

main <- function() {
  initial_state <- 'start'
  initial_data <- ''
  steps <- 5
  result <- state_machine(initial_state, initial_data, steps)
  print(result)
}

main()