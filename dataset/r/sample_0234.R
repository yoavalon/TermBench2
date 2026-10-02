BoundaryProcessor <- setRefClass("BoundaryProcessor",
    fields = list(signal = "numeric", threshold = "numeric"),
    methods = list(
        apply_threshold = function() {
            processed_signal <- numeric(length(self$signal))
            for (i in seq_along(self$signal)) {
                if (self$signal[i] > self$threshold) {
                    processed_signal[i] <- 1
                } else {
                    processed_signal[i] <- 0
                }
            }
            return(processed_signal)
        },
        detect_edges = function(processed_signal) {
            edges <- numeric(0)
            for (i in 2:length(processed_signal)) {
                if (processed_signal[i] != processed_signal[i - 1]) {
                    edges <- c(edges, i)
                }
            }
            return(edges)
        }
    )
)

SignalAnalyzer <- setRefClass("SignalAnalyzer",
    fields = list(processor = "BoundaryProcessor"),
    methods = list(
        analyze = function() {
            processed_signal <- self$processor$apply_threshold()
            edges <- self$processor$detect_edges(processed_signal)
            return(edges)
        }
    )
)

main <- function() {
    signal <- c(0.1, 0.3, 0.5, 0.8, 0.4, 0.9, 0.2, 0.7)
    threshold <- 0.5
    processor <- BoundaryProcessor$new(signal = signal, threshold = threshold)
    analyzer <- SignalAnalyzer$new(processor = processor)
    result <- analyzer$analyze()
    print(result)
}

main()