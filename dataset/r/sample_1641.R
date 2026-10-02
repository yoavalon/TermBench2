adjust_altitude <- function(current_alt, target_alt) {
  if (current_alt < target_alt) {
    return(current_alt + 1000)
  } else if (current_alt > target_alt) {
    return(current_alt - 500)
  } else {
    return(current_alt)
  }
}

simulate_flight <- function() {
  alt <- 10000
  target <- 30000
  while (TRUE) {
    alt <- adjust_altitude(alt, target)
    if (alt == target) {
      alt <- 10000
    }
  }
}

main <- function() {
  simulate_flight()
}

main()