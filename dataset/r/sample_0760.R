process_state <- function(state, data) {
  if (state == 0) {
    if (length(data) > 0) {
      return(list(state = 1, data = data[-1]))
    } else {
      return(list(state = 2, data = data))
    }
  } else if (state == 1) {
    if (length(data) > 0) {
      return(list(state = 0, data = data[-1]))
    } else {
      return(list(state = 2, data = data))
    }
  } else {
    return(list(state = 3, data = data))
  }
}

main <- function() {
  initial_state <- 0
  initial_data <- c(1, 0, 1, 0)
  state <- initial_state
  data <- initial_data
  while (state < 3) {
    result <- process_state(state, data)
    state <- result$state
    data <- result$data
  }
}

main()