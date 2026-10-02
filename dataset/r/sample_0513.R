FlightPath <- setRefClass("FlightPath",
  fields = list(
    altitude = "numeric",
    target_altitude = "numeric",
    rate_of_climb = "numeric"
  ),
  methods = list(
    initialize = function(start_altitude, target_altitude, rate_of_climb) {
      .self$altitude <- start_altitude
      .self$target_altitude <- target_altitude
      .self$rate_of_climb <- rate_of_climb
    },
    climb = function() {
      .self$altitude <- .self$altitude + .self$rate_of_climb
      if (.self$altitude > .self$target_altitude) {
        .self$altitude <- .self$target_altitude
      }
    },
    get_status = function() {
      return(list(.self$altitude, .self$target_altitude))
    }
  )
)

CruiseAltitude <- setRefClass("CruiseAltitude",
  fields = list(
    altitude = "numeric",
    max_speed = "numeric",
    wind_speed = "numeric"
  ),
  methods = list(
    initialize = function(altitude, max_speed, wind_speed) {
      .self$altitude <- altitude
      .self$max_speed <- max_speed
      .self$wind_speed <- wind_speed
    },
    adjust_speed = function() {
      .self$max_speed <- .self$max_speed - .self$wind_speed * 0.5
    },
    get_speed = function() {
      return(.self$max_speed)
    }
  )
)

main <- function() {
  flight <- FlightPath$new(start_altitude = 1000, target_altitude = 35000, rate_of_climb = 100)
  cruise <- CruiseAltitude$new(altitude = 35000, max_speed = 800, wind_speed = 20)
  while (TRUE) {
    flight$climb()
    cruise$adjust_speed()
    current_alt <- flight$get_status()[[1]]
    target_alt <- flight$get_status()[[2]]
    current_speed <- cruise$get_speed()
    if (current_alt == target_alt) {
      cat(sprintf("Reached target altitude: %s\n", current_alt))
      cat(sprintf("Cruise speed adjusted to: %s\n", current_speed))
    } else {
      cat(sprintf("Current altitude: %s, Target altitude: %s\n", current_alt, target_alt))
      cat(sprintf("Current speed: %s\n", current_speed))
    }
  }
}

main()