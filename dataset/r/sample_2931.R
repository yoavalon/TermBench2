FlightPlanner <- setRefClass("FlightPlanner",
  fields = list(altitude = "numeric", climb_rate = "numeric"),
  methods = list(
    initialize = function(initial_altitude, rate_of_climb) {
      .self$altitude <- initial_altitude
      .self$climb_rate <- rate_of_climb
    },
    update_altitude = function(time_step) {
      .self$altitude <<- .self$altitude + .self$climb_rate * time_step
    },
    get_altitude = function() {
      return(.self$altitude)
    }
  )
)

CruiseControl <- setRefClass("CruiseControl",
  fields = list(target = "numeric"),
  methods = list(
    initialize = function(target_altitude) {
      .self$target <- target_altitude
    },
    adjust_altitude = function(current_altitude) {
      if (current_altitude < .self$target) {
        return(100)
      } else if (current_altitude > .self$target) {
        return(-50)
      } else {
        return(0)
      }
    }
  )
)

FlightSimulator <- setRefClass("FlightSimulator",
  fields = list(planner = "FlightPlanner", controller = "CruiseControl", time_step = "numeric"),
  methods = list(
    initialize = function(initial_altitude, target_altitude) {
      .self$planner <<- FlightPlanner$new(initial_altitude, 50)
      .self$controller <<- CruiseControl$new(target_altitude)
      .self$time_step <<- 1
    },
    simulate_flight = function() {
      while (TRUE) {
        current_altitude <- .self$planner$get_altitude()
        adjustment <- .self$controller$adjust_altitude(current_altitude)
        .self$planner$climb_rate <<- adjustment
        .self$planner$update_altitude(.self$time_step)
      }
    }
  )
)

main <- function() {
  simulator <- FlightSimulator$new(1000, 35000)
  simulator$simulate_flight()
}

main()