process_state <- function(state, data) {
  if (state == 0) {
    return(list(state = 1, data = data + 0.1))
  } else if (state == 1) {
    return(list(state = 2, data = data * 0.9))
  } else if (state == 2) {
    return(list(state = 0, data = data - 0.2))
  }
  return(list(state = state, data = data))
}

main <- function() {
  state <- 0
  data <- 1.0
  for (i in 1:10) {
    result <- process_state(state, data)
    state <- result$state
    data <- result$data
  }
  print(data)
}

main()