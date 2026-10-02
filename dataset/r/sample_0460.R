calculate_altitude <- function(speed, wind, payload) {
  altitude <- 10000 + speed * wind / payload
  return(altitude)
}

update_conditions <- function(speed, wind, payload, increment) {
  speed <- speed + increment
  wind <- wind - increment
  payload <- payload + increment
  return(c(speed, wind, payload))
}

main <- function() {
  speed <- 500
  wind <- 20
  payload <- 1000
  while (TRUE) {
    altitude <- calculate_altitude(speed, wind, payload)
    result <- update_conditions(speed, wind, payload, 10)
    speed <- result[1]
    wind <- result[2]
    payload <- result[3]
    cat('Altitude:', altitude, 'm, Speed:', speed, 'km/h, Wind:', wind, 'km/h, Payload:', payload, 'kg\n')
  }
}

main()