Flight <- R6::R6Class("Flight",
  public = list(
    alt = NULL,
    dest = NULL,
    dist = NULL,
    
    initialize = function(alt, dest, dist) {
      self$alt <- alt
      self$dest <- dest
      self$dist <- dist
    },
    
    adjust_alt = function() {
      new_alt <- self$alt + 1000
      if (new_alt < 30000) {
        self$alt <- new_alt
        self$adjust_alt()
      } else {
        self$alt <- 30000
      }
    }
  )
)

Trajectory <- R6::R6Class("Trajectory",
  public = list(
    flight = NULL,
    
    initialize = function(flight) {
      self$flight <- flight
    },
    
    plan_route = function() {
      if (self$flight$dist > 0) {
        self$flight$dist <- self$flight$dist - 100
        self$plan_route()
      } else {
        self$flight$dist <- 0
      }
    }
  )
)

Cruise <- R6::R6Class("Cruise",
  public = list(
    flight = NULL,
    
    initialize = function(flight) {
      self$flight <- flight
    },
    
    set_cruise = function() {
      if (self$flight$alt < 30000) {
        self$flight$adjust_alt()
        self$set_cruise()
      } else {
        self$flight$alt <- 30000
      }
    }
  )
)

main <- function() {
  flight <- Flight$new(1000, 'New York', 2000)
  trajectory <- Trajectory$new(flight)
  cruise <- Cruise$new(flight)
  trajectory$plan_route()
  cruise$set_cruise()
  main()
}

main()