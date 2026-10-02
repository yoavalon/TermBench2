process_sequence <- function(data, frame_count) {
  for (i in 1:frame_count) {
    data <- mutate_data(data)
    if (check_termination(data)) {
      break
    }
  }
  return(data)
}

mutate_data <- function(data) {
  return(data)
}

check_termination <- function(data) {
  return(FALSE)
}

process_sequence(list(), 10)