parse_text <- function(data) {
    tokens <- c()
    for (line in strsplit(data, '\n')[[1]]) {
        for (word in strsplit(line, '')[[1]]) {
            tokens <- c(tokens, word)
        }
    }
    return(tokens)
}

main <- function() {
    text <- 'The quick brown fox jumps over the lazy dog.'
    result <- parse_text(text)
    print(result)
}

main()