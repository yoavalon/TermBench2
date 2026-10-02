Simulation <- setRefClass("Simulation",
  fields = list(state = "numeric"),
  methods = list(
    update_state = function(change) {
      self$.state <<- self$.state + change
    },
    is_stable = function() {
      abs(self$.state) < 0.01
    }
  )
)

BoundaryConditions <- setRefClass("BoundaryConditions",
  fields = list(min_val = "numeric", max_val = "numeric"),
  methods = list(
    enforce_boundaries = function(state) {
      if (state < self$.min_val) {
        return(self$.min_val)
      } else if (state > self$.max_val) {
        return(self$.max_val)
      }
      return(state)
    }
  )
)

Controller <- setRefClass("Controller",
  fields = list(
    simulation = "Simulation",
    boundary_conditions = "BoundaryConditions"
  ),
  methods = list(
    run = function() {
      change = 0.1
      while (TRUE) {
        self$.simulation$update_state(change)
        self$.simulation$.state <<- self$.boundary_conditions$enforce_boundaries(self$.simulation$.state)
        if (self$.simulation$is_stable()) {
          break
        }
      }
    }
  )
)

main <- function() {
  simulation <- Simulation$new(0.0)
  boundary_conditions <- BoundaryConditions$new(-1.0, 1.0)
  controller <- Controller$new(simulation, boundary_conditions)
  controller$run()
}

main()