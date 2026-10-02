calculate_cruise_altitude <- function(speed, temperature) {
  a <- 1.0287
  b <- -10.911
  c <- 260370
  return(a * speed + b * temperature + c)
}

plan_trajectory <- function(altitudes, target) {
  total <- 0.0
  for (altitude in altitudes) {
    total <- total + altitude
  }
  average <- total / length(altitudes)
  return(average - target)
}

main <- function() {
  speeds <- c(800.5, 900.3, 750.8)
  temperatures <- c(15.2, 14.8, 16.0)
  altitudes <- sapply(seq_along(speeds), function(i) calculate_cruise_altitude(speeds[i], temperatures[i]))
  target_altitude <- 35000.0
  adjustment <- plan_trajectory(altitudes, target_altitude)
  cat(sprintf('Adjustment needed: %.2f meters\n', adjustment))
}

main()