apply_boundary_conditions <- function(signal, condition_type) {
  if (condition_type == 'zero') {
    return(ifelse(signal < 0, 0, signal))
  } else if (condition_type == 'clip') {
    return(ifelse(signal > 1, 1, ifelse(signal < 0, 0, signal)))
  } else {
    return(signal)
  }
}

process_signal <- function(signal, condition) {
  processed_signal <- apply_boundary_conditions(signal, condition)
  return(processed_signal * 0.5)
}

main <- function() {
  data <- c(0.1, -0.3, 0.8, 1.2, -0.5, 0.9)
  result <- process_signal(data, 'clip')
  print(result)
}

main()