library(matrixStats)

StateSimulator <- setRefClass("StateSimulator",
  fields = list(conditions = "numeric", boundaries = "list", iteration = "numeric"),
  methods = list(
    initialize = function(initial_conditions, boundary_conditions) {
      .self$conditions <- initial_conditions
      .self$boundaries <- boundary_conditions
      .self$iteration <- 0
    },
    update_conditions = function() {
      .self$conditions <- pmin(pmax(.self$conditions + runif(length(.self$conditions), min=0, max=0.1), .self$boundaries[[1]]), .self$boundaries[[2]])
    },
    check_stability = function() {
      if (all(abs(.self$conditions - .self$boundaries[[1]]) < 0.01) || all(abs(.self$conditions - .self$boundaries[[2]]) < 0.01)) {
        return(TRUE)
      }
      return(FALSE)
    }
  )
)

BoundaryConditions <- setRefClass("BoundaryConditions",
  fields = list(limit1 = "numeric", limit2 = "numeric"),
  methods = list(
    initialize = function(lower, upper) {
      .self$limit1 <- lower
      .self$limit2 <- upper
    },
    get_boundaries = function() {
      return(list(.self$limit1, .self$limit2))
    }
  )
)

simulate_state <- function(initial, boundaries, max_iterations) {
  simulator <- StateSimulator$new(initial, boundaries)
  for (i in 1:max_iterations) {
    simulator$update_conditions()
    if (simulator$check_stability()) {
      break
    }
  }
  return(simulator$conditions)
}

main <- function() {
  initial_conditions <- c(0.5, 0.5, 0.5)
  boundary_conditions <- BoundaryConditions$new(0, 1)
  max_iterations <- 100
  final_state <- simulate_state(initial_conditions, boundary_conditions$get_boundaries(), max_iterations)
  print(final_state)
}

main()