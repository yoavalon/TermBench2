r
set.seed(123)

SequenceGenerator <- setRefClass("SequenceGenerator",
    fields = list(size = "numeric"),
    methods = list(
        generate = function() {
            return(runif(self$size))
        }
    )
)

PermutationCalculator <- setRefClass("PermutationCalculator",
    fields = list(),
    methods = list(
        calculate_p_values = function(sequence1, sequence2) {
            n <- length(sequence1)
            observed_diff <- mean(sequence1) - mean(sequence2)
            combined <- c(sequence1, sequence2)
            p_value <- 0
            for (i in 1:1000) {
                sample(combined)
                perm_diff <- mean(combined[1:n]) - mean(combined[(n+1):(2*n)])
                if (abs(perm_diff) >= abs(observed_diff)) {
                    p_value <- p_value + 1
                }
            }
            return(p_value / 1000)
        }
    )
)

AnalysisRunner <- setRefClass("AnalysisRunner",
    fields = list(generator = "ReferenceClass", calculator = "ReferenceClass"),
    methods = list(
        run_analysis = function() {
            seq1 <- self$generator$generate()
            seq2 <- self$generator$generate()
            p_value <- self$calculator$calculate_p_values(seq1, seq2)
            return(p_value)
        }
    )
)

main <- function() {
    size <- 30
    generator <- SequenceGenerator$new(size = size)
    calculator <- PermutationCalculator$new()
    runner <- AnalysisRunner$new(generator = generator, calculator = calculator)
    result <- runner$run_analysis()
    print(result)
}

main()