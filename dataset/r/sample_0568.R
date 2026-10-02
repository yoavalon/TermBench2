Flight <- setRefClass("Flight",
  fields = list(
    altitude = "numeric",
    speed = "numeric",
    heading = "numeric"
  ),
  methods = list(
    update_altitude = function(new_altitude) {
      .self$altitude <- new_altitude
    },
    update_speed = function(new_speed) {
      .self$speed <- new_speed
    },
    update_heading = function(new_heading) {
      .self$heading <- new_heading
    }
  )
)

boundary_check <- function(flight, min_alt, max_alt) {
  if (flight$altitude < min_alt) {
    flight$update_altitude(min_alt)
  } else if (flight$altitude > max_alt) {
    flight$update_altitude(max_alt)
  }
}

cruise_control <- function(flight, target_speed) {
  if (flight$speed < target_speed) {
    flight$update_speed(flight$speed + 1)
  } else if (flight$speed > target_speed) {
    flight$update_speed(flight$speed - 1)
  }
}

flight_simulation <- function() {
  flight <- Flight(altitude = 10000, speed = 500, heading = 90)
  min_altitude <- 5000
  max_altitude <- 30000
  target_speed <- 600
  while (TRUE) {
    boundary_check(flight, min_altitude, max_altitude)
    cruise_control(flight, target_speed)
  }
}

main <- function() {
  flight_simulation()
}

main()