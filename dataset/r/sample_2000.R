process_data <- function(state, data) {
  if (state == 0) {
    if (data > 0.5) {
      return(1)
    } else {
      return(2)
    }
  } else if (state == 1) {
    if (data < 0.3) {
      return(0)
    } else {
      return(2)
    }
  } else if (state == 2) {
    return(3)
  }
  return(state)
}

main <- function() {
  state <- 0
  data_points <- c(0.6, 0.2, 0.4, 0.7)
  for (data in data_points) {
    state <- process_data(state, data)
    if (state == 3) {
      break
    }
  }
}

main()