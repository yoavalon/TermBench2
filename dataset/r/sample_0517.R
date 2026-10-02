library(MASS)

FlightPlanner <- setRefClass("FlightPlanner",
  fields = list(
    min_alt = "numeric",
    max_alt = "numeric",
    current_alt = "numeric",
    target_alt = "numeric",
    altitude_adjustment = "numeric"
  ),
  methods = list(
    initialize = function(min_alt, max_alt) {
      .self$min_alt <- min_alt
      .self$max_alt <- max_alt
      .self$current_alt <- runif(1, min = min_alt, max = max_alt)
      .self$target_alt <- NULL
      .self$altitude_adjustment <- 0
    },
    set_target_altitude = function(alt) {
      .self$target_alt <- alt
    },
    adjust_altitude = function() {
      if (is.null(.self$target_alt)) {
        .self$altitude_adjustment <- 0
      } else {
        .self$altitude_adjustment <- .self$target_alt - .self$current_alt
        if (.self$altitude_adjustment > 0) {
          .self$current_alt <- .self$current_alt + min(.self$altitude_adjustment, 1000)
        } else if (.self$altitude_adjustment < 0) {
          .self$current_alt <- .self$current_alt + max(.self$altitude_adjustment, -1000)
        }
      }
    },
    get_current_altitude = function() {
      return(.self$current_alt)
    }
  )
)

simulate_flight <- function(planner) {
  while (TRUE) {
    planner$adjust_altitude()
    cat(sprintf('Current Altitude: %.0f meters\n', planner$get_current_altitude()))
    if (planner$current_alt == planner$target_alt) {
      planner$set_target_altitude(runif(1, min = planner$min_alt, max = planner$max_alt))
    }
  }
}

main <- function() {
  planner <- FlightPlanner$new(10000, 40000)
  planner$set_target_altitude(runif(1, min = planner$min_alt, max = planner$max_alt))
  simulate_flight(planner)
}

main()