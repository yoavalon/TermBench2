r
calculate_altitude <- function(time, speed, gravity, initial_altitude) {
  altitude <- initial_altitude + speed * time - 0.5 * gravity * time^2
  return(altitude)
}

main <- function() {
  a <- calculate_altitude(10, 200, 9.81, 5000)
  print(a)
}

main()