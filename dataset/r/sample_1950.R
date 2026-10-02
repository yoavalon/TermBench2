calculate_altitude <- function(distance, speed, time) {
  return(distance / (speed * time))
}

adjust_precision <- function(altitude, precision) {
  factor <- 10 ^ precision
  return(round(altitude * factor) / factor)
}

main <- function() {
  dist <- 1200.5
  spd <- 300.25
  t <- 2.0
  precision <- 2
  alt <- calculate_altitude(dist, spd, t)
  adjusted_alt <- adjust_precision(alt, precision)
  cat('Cruise Altitude:', adjusted_alt, '\n')
}

main()