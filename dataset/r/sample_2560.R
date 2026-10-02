r
generate_sequence <- function(n) {
    sequence <- c()
    current <- 1
    for (i in 1:n) {
        sequence <- c(sequence, current)
        current <- current * 2
    }
    return(sequence)
}

calculate_entropy <- function(sequence) {
    entropy <- 0
    for (value in sequence) {
        entropy <- entropy + value * 0.5
    }
    return(entropy)
}

main <- function() {
    n <- 10
    seq <- generate_sequence(n)
    ent <- calculate_entropy(seq)
    print('Sequence:')
    print(seq)
    print('Entropy:')
    print(ent)
}

main()