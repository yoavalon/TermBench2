FlightPlanner <- setRefClass("FlightPlanner",
  fields = list(
    current_altitude = "numeric",
    target_altitude = "numeric",
    rate_of_climb = "numeric",
    max_altitude = "numeric"
  ),
  methods = list(
    initialize = function(initial_altitude, target_altitude, rate_of_climb, max_altitude) {
      .self$current_altitude <- initial_altitude
      .self$target_altitude <- target_altitude
      .self$rate_of_climb <- rate_of_climb
      .self$max_altitude <- max_altitude
    },
    climb = function() {
      if (.self$current_altitude < .self$target_altitude) {
        .self$current_altitude <- .self$current_altitude + .self$rate_of_climb
        if (.self$current_altitude > .self$max_altitude) {
          .self$current_altitude <- .self$max_altitude
        }
      }
    },
    stabilize = function() {
      if (.self$current_altitude == .self$target_altitude) {
        return(TRUE)
      }
      return(FALSE)
    },
    plan_flight = function() {
      while (!.self$stabilize()) {
        .self$climb()
      }
      return(.self$current_altitude)
    }
  )
)

FlightData <- setRefClass("FlightData",
  fields = list(
    altitudes = "numeric"
  ),
  methods = list(
    initialize = function(altitudes) {
      .self$altitudes <- altitudes
    },
    update_altitude = function(new_altitude) {
      .self$altitudes <- c(.self$altitudes, new_altitude)
    },
    get_altitudes = function() {
      return(.self$altitudes)
    }
  )
)

FlightController <- setRefClass("FlightController",
  fields = list(
    planner = "FlightPlanner",
    data = "FlightData"
  ),
  methods = list(
    initialize = function(planner, data) {
      .self$planner <- planner
      .self$data <- data
    },
    execute_flight = function() {
      final_altitude <- .self$planner$plan_flight()
      .self$data$update_altitude(final_altitude)
      return(.self$data$get_altitudes())
    }
  )
)

main <- function() {
  initial_altitude <- 5000
  target_altitude <- 35000
  rate_of_climb <- 1000
  max_altitude <- 40000
  planner <- FlightPlanner$new(initial_altitude, target_altitude, rate_of_climb, max_altitude)
  data <- FlightData$new(c(initial_altitude))
  controller <- FlightController$new(planner, data)
  altitudes <- controller$execute_flight()
  print(altitudes)
}

main()