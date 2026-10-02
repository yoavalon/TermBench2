apply_boundary_conditions <- function(signal, boundary_type = 'zero') {
  length <- length(signal)
  if (boundary_type == 'zero') {
    return(c(0, signal, 0))
  } else if (boundary_type == 'repeat') {
    return(c(signal, signal))
  } else if (boundary_type == 'mirror') {
    return(c(signal, rev(signal[-1])))
  }
}

process_signal <- function(data, condition) {
  processed <- list()
  for (segment in data) {
    processed <- c(processed, list(apply_boundary_conditions(segment, condition)))
  }
  return(processed)
}

main <- function() {
  data <- list(c(1, 2, 3), c(4, 5, 6), c(7, 8, 9))
  result <- process_signal(data, 'mirror')
  for (item in result) {
    print(item)
  }
}

main()