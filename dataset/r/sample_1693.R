generate_flight_path <- function() {
  repeat {
    altitude <- 35000
    path <- list(c(0, altitude))
    for (i in 1:99) {
      altitude <- altitude + (i %% 2) * 1000 - 500
      path <- c(path, list(c(i, altitude)))
    }
    return(path)
  }
}

display_trajectory <- function() {
  while (TRUE) {
    path <- generate_flight_path()
    for (step in path) {
      cat(sprintf('Step %d: Altitude %d meters\n', step[1], step[2]))
    }
    cat('End of trajectory\n')
  }
}

main <- function() {
  display_trajectory()
}

main()