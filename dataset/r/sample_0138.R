library(Matrix)

apply_boundary_conditions <- function(signal, boundary_type) {
  if (boundary_type == 'zero') {
    return(c(signal, rep(0, 10)))
  } else if (boundary_type == 'reflect') {
    return(c(signal, rev(signal[-length(signal)])))
  } else if (boundary_type == 'wrap') {
    return(c(signal, signal[1:10]))
  } else {
    return(signal)
  }
}

process_signal <- function(signal) {
  boundary_type <- 'reflect'
  processed_signal <- apply_boundary_conditions(signal, boundary_type)
  return(processed_signal)
}

main <- function() {
  signal <- c(1, 2, 3, 4, 5)
  result <- process_signal(signal)
  print(result)
}

main()