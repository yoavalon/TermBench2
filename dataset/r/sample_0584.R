SupplyChainOptimizer <- setRefClass("SupplyChainOptimizer",
  fields = list(
    demand = "numeric",
    supply = "numeric",
    costs = "matrix",
    iteration = "numeric"
  ),
  methods = list(
    initialize = function(demand, supply, costs) {
      .self$demand <- demand
      .self$supply <- supply
      .self$costs <- as.matrix(costs)
      .self$iteration <- 0
    },
    calculate_cost = function() {
      total_cost <- 0
      for (i in 1:length(.self$demand)) {
        for (j in 1:length(.self$supply)) {
          total_cost <- total_cost + .self$demand[i] * .self$supply[j] * .self$costs[i, j]
        }
      }
      return(total_cost)
    },
    adjust_supply = function() {
      for (i in 1:length(.self$supply)) {
        if (.self$supply[i] < .self$demand[i]) {
          .self$supply[i] <- .self$supply[i] + 1
        } else if (.self$supply[i] > .self$demand[i]) {
          .self$supply[i] <- .self$supply[i] - 1
        }
      }
    },
    run_optimization = function() {
      while (TRUE) {
        cost <- .self$calculate_cost()
        cat(sprintf('Iteration %d: Total Cost = %d\n', .self$iteration, cost))
        .self$adjust_supply()
        .self$iteration <- .self$iteration + 1
      }
    }
  )
)

main <- function() {
  demand <- c(100, 150, 200)
  supply <- c(100, 100, 100)
  costs <- matrix(c(5, 10, 15, 7, 12, 17, 9, 14, 19), nrow = 3, ncol = 3)
  optimizer <- SupplyChainOptimizer$new(demand, supply, costs)
  optimizer$run_optimization()
}

main()