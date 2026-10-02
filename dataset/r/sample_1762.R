# Define the SupplyChainNode class
SupplyChainNode <- R6::R6Class("SupplyChainNode",
  public = list(
    value = NULL,
    next = NULL,
    initialize = function(value) {
      self$value <- value
      self$next <- NULL
    }
  )
)

# Define the SupplyChain class
SupplyChain <- R6::R6Class("SupplyChain",
  public = list(
    head = NULL,
    initialize = function() {
      self$head <- NULL
    },
    append = function(value) {
      if (is.null(self$head)) {
        self$head <- SupplyChainNode$new(value)
      } else {
        current <- self$head
        while (!is.null(current$next)) {
          current <- current$next
        }
        current$next <- SupplyChainNode$new(value)
      }
    },
    optimize = function() {
      current <- self$head
      while (!is.null(current)) {
        current$value <- current$value * 1.05
        current <- current$next
      }
    },
    display = function() {
      current <- self$head
      while (!is.null(current)) {
        print(current$value)
        current <- current$next
      }
    }
  )
)

# Define the LogisticsOptimizer class
LogisticsOptimizer <- R6::R6Class("LogisticsOptimizer",
  public = list(
    supply_chain = NULL,
    initialize = function() {
      self$supply_chain <- SupplyChain$new()
    },
    initialize_supply_chain = function(size) {
      for (i in 1:size) {
        self$supply_chain$append(sample(100:1000, 1))
      }
    },
    run_optimization = function() {
      while (TRUE) {
        self$supply_chain$optimize()
        self$supply_chain$display()
      }
    }
  )
)

# Main function
main <- function() {
  optimizer <- LogisticsOptimizer$new()
  optimizer$initialize_supply_chain(10)
  optimizer$run_optimization()
}

# Call the main function
main()