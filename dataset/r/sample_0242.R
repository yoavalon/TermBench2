FlightData <- setRefClass("FlightData",
  fields = list(
    altitude = "numeric",
    speed = "numeric",
    distance = "numeric",
    max_altitude = "numeric"
  ),
  methods = list(
    update_altitude = function(new_altitude) {
      if (new_altitude <= .self$max_altitude) {
        .self$altitude <- new_altitude
      } else {
        .self$altitude <- .self$max_altitude
      }
    },
    update_distance = function(new_distance) {
      .self$distance <- new_distance
    }
  )
)

CruisePlanner <- setRefClass("CruisePlanner",
  fields = list(
    flight_data = "FlightData"
  ),
  methods = list(
    calculate_cruise_altitude = function() {
      if (.self$flight_data$speed > 500) {
        return(min(.self$flight_data$altitude + 1000, .self$flight_data$max_altitude))
      } else {
        return(max(.self$flight_data$altitude - 1000, 0))
      }
    },
    adjust_trajectory = function() {
      new_altitude <- .self$calculate_cruise_altitude()
      .self$flight_data$update_altitude(new_altitude)
      .self$flight_data$update_distance(.self$flight_data$distance + 100)
    }
  )
)

main <- function() {
  flight_data <- new("FlightData", altitude = 5000, speed = 600, distance = 0, max_altitude = 10000)
  cruise_planner <- new("CruisePlanner", flight_data = flight_data)
  for (i in 1:10) {
    cruise_planner$adjust_trajectory()
  }
  cat('Final Altitude:', flight_data$altitude, '\n')
  cat('Final Distance:', flight_data$distance, '\n')
}

main()