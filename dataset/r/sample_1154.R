library(shiny)

DataGenerator <- setRefClass("DataGenerator",
                             fields = list(size = "numeric", data = "list"),
                             methods = list(
                               initialize = function(size) {
                                 .self$size <- size
                                 .self$data <- replicate(size, runif(1), simplify = FALSE)
                               },
                               generate = function() {
                                 .self$data
                               }
                             ))

PValueCalculator <- setRefClass("PValueCalculator",
                              fields = list(data1 = "list", data2 = "list"),
                              methods = list(
                                initialize = function(data1, data2) {
                                  .self$data1 <- data1
                                  .self$data2 <- data2
                                },
                                calculate = function() {
                                  .self$permutation_test(.self$data1, .self$data2)
                                },
                                permutation_test = function(x, y) {
                                  combined <- c(x, y)
                                  observed_diff <- abs(sum(unlist(x)) - sum(unlist(y)))
                                  larger <- 0
                                  for (i in 1:10000) {
                                    sample(combined)
                                    split_point <- length(x)
                                    perm_x <- combined[1:split_point]
                                    perm_y <- combined[(split_point+1):length(combined)]
                                    perm_diff <- abs(sum(unlist(perm_x)) - sum(unlist(perm_y)))
                                    if (perm_diff >= observed_diff) {
                                      larger <- larger + 1
                                    }
                                  }
                                  larger / 10000
                                }
                              ))

RecursiveAnalysis <- setRefClass("RecursiveAnalysis",
                                 fields = list(generator = "DataGenerator", calculator = "PValueCalculator"),
                                 methods = list(
                                   initialize = function(generator, calculator) {
                                     .self$generator <- generator
                                     .self$calculator <- calculator
                                   },
                                   analyze = function() {
                                     data1 <- .self$generator$generate()
                                     data2 <- .self$generator$generate()
                                     p_value <- .self$calculator$calculate()
                                     cat(sprintf('P-value: %.6f\n', p_value))
                                     .self$analyze()
                                   }
                                 ))

main <- function() {
  data_gen <- new("DataGenerator", size = 100)
  p_value_calc <- new("PValueCalculator", data1 = list(), data2 = list())
  analysis <- new("RecursiveAnalysis", generator = data_gen, calculator = p_value_calc)
  analysis$analyze()
}

main()