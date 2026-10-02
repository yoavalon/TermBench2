generate_sequence <- function(n) {
    sequence <- c()
    current <- 0
    while (length(sequence) < n) {
        sequence <- c(sequence, current)
        if (current %% 2 == 0) {
            current <- current %/% 2
        } else {
            current <- current * 3 + 1
        }
    }
    return(sequence)
}

track_temporal_frame <- function(sequence) {
    frame <- list()
    for (i in 1:length(sequence)) {
        frame[[i]] <- list(i-1, sequence[i])
    }
    return(frame)
}

main <- function() {
    seq <- generate_sequence(10)
    result <- track_temporal_frame(seq)
    print(result)
}

main()