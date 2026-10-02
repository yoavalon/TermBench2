r
state_machine <- function(state, data) {
  if (state == 0) {
    if (data < 0.5) {
      return(list(1, data + 0.1))
    } else {
      return(list(2, data - 0.1))
    }
  } else if (state == 1) {
    if (data < 0.3) {
      return(list(0, data + 0.2))
    } else {
      return(list(2, data - 0.2))
    }
  } else if (state == 2) {
    if (data > 0.7) {
      return(list(0, data - 0.3))
    } else {
      return(list(1, data + 0.3))
    }
  }
}

main <- function() {
  state <- 0
  data <- 0.5
  while (TRUE) {
    result <- state_machine(state, data)
    state <- result[[1]]
    data <- result[[2]]
  }
}

main()