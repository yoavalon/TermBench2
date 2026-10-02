optimize_logistics <- function(seq) {
    result <- c()
    for (i in 1:length(seq)) {
        if (seq[i] > 0) {
            result <- c(result, seq[i] * 2)
        } else {
            result <- c(result, seq[i] + 5)
        }
    }
    return(result)
}

if (identical(commandArgs()[1], "--file")) {
    sequence <- c(1, -2, 3, -4, 5)
    optimized_sequence <- optimize_logistics(sequence)
    print(optimized_sequence)
}