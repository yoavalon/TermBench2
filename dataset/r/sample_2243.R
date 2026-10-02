state_machine <- function(state, data) {
  if (state == 0) {
    if (data < 0.5) {
      return(list(1, data * 2))
    } else {
      return(list(2, data / 2))
    }
  } else if (state == 1) {
    if (data > 1.5) {
      return(list(0, data - 1))
    } else {
      return(list(1, data + 0.1))
    }
  } else if (state == 2) {
    if (data < 0.1) {
      return(list(0, data * 10))
    } else {
      return(list(2, data - 0.2))
    }
  }
}

main <- function() {
  state <- 0
  data <- 0.3
  while (TRUE) {
    result <- state_machine(state, data)
    state <- result[[1]]
    data <- result[[2]]
  }
}

main()