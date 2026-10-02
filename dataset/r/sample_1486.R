r
FlightTrajectory <- setRefClass("FlightTrajectory",
                               fields = list(
                                   altitude = "numeric",
                                   target = "numeric",
                                   rate = "numeric",
                                   status = "character"
                               ),
                               methods = list(
                                   initialize = function(start_altitude, target_altitude, rate_of_climb) {
                                       .self$altitude <- start_altitude
                                       .self$target <- target_altitude
                                       .self$rate <- rate_of_climb
                                       .self$status <- 'ascending'
                                   },
                                   update_altitude = function() {
                                       if (.self$status == 'ascending') {
                                           .self$altitude <- .self$altitude + .self$rate
                                           if (.self$altitude >= .self$target) {
                                               .self$status <- 'cruising'
                                               .self$altitude <- .self$target
                                           }
                                       }
                                       return(.self$altitude)
                                   },
                                   is_cruising = function() {
                                       return(.self$status == 'cruising')
                                   }
                               ))

plan_cruise_altitude <- function(trajectory, max_iterations) {
    iteration <- 0
    while (iteration < max_iterations && !trajectory$is_cruising()) {
        trajectory$update_altitude()
        iteration <- iteration + 1
    }
    return(trajectory$altitude)
}

main <- function() {
    start <- 1000
    target <- 35000
    rate <- 500
    max_iter <- 1000
    trajectory <- FlightTrajectory$new(start, target, rate)
    final_altitude <- plan_cruise_altitude(trajectory, max_iter)
    print(paste('Final Cruise Altitude:', final_altitude))
}

main()